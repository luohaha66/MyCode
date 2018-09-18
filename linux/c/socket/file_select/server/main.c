#include "server.h"

int main()
{
	int len = 0;
	int num = 0;
	int sockfd = 0;
	int clifd = 0;
	int FDSIZE = 0;
	int fd = 0;
	int value = 0;
	fd_set fds;
	fd_set rfds;
	fd_set fdss;
	fd_set wfds;
	struct sockaddr_in ser;
	struct sockaddr_in cli;
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
	
	FD_ZERO(&rfds);
	FD_SET(sockfd, &rfds);
	FD_ZERO(&wfds);
	FDSIZE = sockfd + 1;
	
	while (1)
	{
		fds = rfds;
		fdss = wfds;
		struct timeval timeout;
		memset(&timeout, 0, sizeof(struct timeval));
		timeout.tv_sec = 2;
		timeout.tv_usec = 500000;
		if (value = select(FDSIZE, &fds, &fdss, NULL, &timeout) == -1)
			{
				perror("select error:");
				exit(EXIT_FAILURE);
			}
		for(fd = 0; fd < FDSIZE; fd++)
		{
			if (FD_ISSET(fd, &fds))
				{
					if (fd == sockfd)
						{
							len = sizeof(struct sockaddr_in);
							if ((clifd = accept(sockfd, (struct sockaddr*)&cli, &len)) == -1)
        				{
        					perror("socket error:");
        			  	exit(EXIT_FAILURE);
        		  	}
        		   printf("New Connect From: %s\n", inet_ntoa(cli.sin_addr));
        		   FD_SET(clifd, &rfds);
        		   FD_SET(clifd, &wfds);
        		   FDSIZE = (clifd >= FDSIZE ? clifd + 1 : FDSIZE);
						}
					else 
						{
							run(fd, &rfds, &wfds);
						}
				}
		}
		sleep(1);
	}
	close(sockfd);
}