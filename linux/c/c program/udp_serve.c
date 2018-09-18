#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#define PORT 6666
int main(int argc,char *argv[])
{
int sockfd;
char buf[1024];
int addrlen;
struct sockaddr_in serve_addr;
struct sockaddr_in client_addr;
if((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
{
perror("socket");
exit(-1);
}
bzero(&serve_addr,sizeof(serve_addr));
serve_addr.sin_family=AF_INET;
serve_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serve_addr.sin_port=htons(PORT);
if(bind(sockfd,(struct sockaddr *)(&serve_addr),sizeof(serve_addr))==-1)
{
perror("error");
exit(-1);
}
while(1)
{
addrlen=sizeof(serve_addr);
memset(buf,0,sizeof(buf));
 recvfrom(sockfd,buf,1024,0,(struct sockaddr *)(&serve_addr),&addrlen);
printf("receive msg from %s,port is %d,is %s\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port),buf);
}
close(sockfd);
}
