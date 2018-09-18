#include "server.h"

int main()
{
	int len = 0;
	int num = 0;
	int fd = 0;
	int sockfd = 0;
	int clifd = 0;
	int value = 0;
	int i = 0;
	struct sockaddr_in ser;
	struct sockaddr_in cli;
	struct epoll_event evt[50];
	struct epoll_event even;
	char buf[128] = {0};
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			perror("socket error:");
			exit(EXIT_FAILURE);
		}
	memset(&ser, 0, sizeof(ser));
	ser.sin_family = AF_INET;
	ser.sin_port = htons(8888);
	ser.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockfd, (struct sockaddr*)&ser, sizeof(struct sockaddr)) == -1)
		{
			perror("bind error:");
			exit(EXIT_FAILURE);
		}
	listen(sockfd, 5);
	len = sizeof(struct sockaddr_in);
	if ((fd = epoll_create(50)) == -1)
		{
			perror("epoll_create error:");
			exit(EXIT_FAILURE);
		}
	even.events = EPOLLIN | EPOLLET;
	even.data.fd = sockfd;
	if (epoll_ctl(fd, EPOLL_CTL_ADD, sockfd, &even) == -1)
		{
			perror("epoll_ctl error:");
			exit(EXIT_FAILURE);
		}
	while(1)
	{
		if ((value = epoll_wait(fd, evt, 50, 1000)) == -1)
			{
				perror("epoll_wait error:");
				exit(EXIT_FAILURE);
			}
		for(i = 0; i < value; i++)
		{
  		if (eve[i].events & EPOLLIN)
  			{
  				if (evt[i].data.fd == sockfd)
      			{
      				if ((clifd = accept(sockfd, (struct sockaddr*)&cli, &len)) == -1)
          			{
          				perror("socket error:");
          			  exit(EXIT_FAILURE);
          			}
          		even.events = EPOLLIN | EPOLLET;
          		even.data.fd = clifd;
          		if (epoll_ctl(fd, EPOLL_CTL_ADD, clifd, &even) == -1)
            		{
            			perror("epoll_ctl error:");
            			exit(EXIT_FAILURE);
            		}
            	printf("New Connect From: %s\n", inet_ntoa(cli.sin_addr));
      			}
      		else 
      			{
      				run(evt[i].data.fd);
      			}
  			}
		}
	}
	close(sockfd);
}