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
struct sockaddr_in client_addr;
if((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
{
 perror("error");
exit(-1);
}
bzero(&client_addr,sizeof(client_addr));
client_addr.sin_family=AF_INET;
client_addr.sin_addr.s_addr=inet_addr(argv[1]);
client_addr.sin_port=htons(PORT);
while(1)
{
 memset(buf,0,sizeof(buf));
printf("pleasec input char:\n");
fgets(buf,1024,stdin);
sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)(&client_addr),sizeof(client_addr));
}
close(sockfd);
}
