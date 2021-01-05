#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netdb.h>
#define PORT 3333
int main(int argc,char *argv[])
{
int sockfd;
char buf[1024];
struct hostent *host;
struct sockaddr_in client_addr;
if((host=gethostbyname(argv[1]))==NULL)
{
perror("host");
exit(-1);
}
printf("123\n");
if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
{
perror("socket");
exit(-1);
}
bzero(&client_addr,sizeof(client_addr));
client_addr.sin_family=AF_INET;
client_addr.sin_addr=*((struct in_addr *)host->h_addr);
client_addr.sin_port=htons(PORT);
printf("456\n");
if(connect(sockfd,(struct sockaddr *)(&client_addr),sizeof(struct sockaddr))==-1)
{
perror("connect");
exit(-1);
}
printf("connect success\n");
printf("please input char:\n");
fgets(buf,1024,stdin);
write(sockfd,buf,1024);
sleep(5);
memset(buf,0,sizeof(buf));
close(sockfd);
}

