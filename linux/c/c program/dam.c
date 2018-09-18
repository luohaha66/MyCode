#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<syslog.h>
#define MAXFILE 65535
int main()
{
 pid_t pid;
int len,i,fd;
char *buf="I love you\n";
len=strlen(buf);
pid=fork();
if(pid>0)
exit(0);
openlog("dam",LOG_PID,LOG_DAEMON);
if( setsid()<0)
{
syslog(LOG_ERR,"%s\n","setsid");
exit(0);
}
if(chdir("/")<0)
{
syslog(LOG_ERR,"%s\n","chdir");
exit(0);
}
umask(0);
for(i=0;i<MAXFILE;i++)
close(i);
while(1)
{
if((fd=open("/root/dam.log",O_CREAT|O_WRONLY|O_APPEND,0600))<0)
{
syslog(LOG_ERR,"%S\n","open");
exit(0);
}
write(fd,buf,len+1);
close(fd);
sleep(10);
}
closelog();
return 0;
}
