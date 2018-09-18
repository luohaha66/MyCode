#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#define PORT 3333
int main(int argc,char* argv[])
{
	int sockfd,new_fd;
	char buf[1024];
	int sinsize;
	int n;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket");
		exit(-1);
	}
	bzero(&server_addr,sizeof(struct sockaddr_in));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	server_addr.sin_port=htons(PORT);
	n=1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&n,sizeof(int)); //quickly start
		if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
		{
			perror("bind");
			exit(-1);
		}
	if(listen(sockfd,5)==-1)
	{
		perror("listen");
		exit(-1);
	}
	while(1)
	{
		sinsize=sizeof(struct sockaddr_in);
		if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sinsize))==-1)
		{
			perror("accept");
			exit(-1);
		}
		if((n=fork())==0)
		{
			printf("receive connect from %s\n",inet_ntoa(client_addr.sin_addr));
			if(read(new_fd,buf,1024)==-1)
			{
				perror("read");
				exit(-1);
			}
			printf("serve received %s\n",buf);
			memset(buf,0,sizeof(buf));
			close(sockfd);
			close(new_fd);
			exit(0);
		}
		else
			close(new_fd);
	}

}
