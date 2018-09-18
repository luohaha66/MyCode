#include "server.h"

int main()
{
	int len = 0;
	int i = 0;
	int j = 0;
	int num = 0;
	int value = 0;
	int sockfd = 0;
	int clifd = 0;
	int FDSIZE = 0;
	int fd = 0;
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
	
	struct pollfd fds[512];
	struct pollfd pfd;
	for(i = 0; i < 512; i++)
	{
		fds[i].fd = -1;
	}
	pfd.fd = sockfd;
	pfd.events = POLLIN;
	fds[0] = pfd;
	FDSIZE = sockfd + 1;
	while(1)
	{
		if ((value = poll(fds, FDSIZE, 500)) == -1)
			{
				perror("poll error:");
				exit(EXIT_FAILURE);
			}
		for(i = 0; i < FDSIZE; i++)
		{
			if ((fds[i].revents & POLLIN) && (fds[i].fd != -1))
				{
					fd = fds[i].fd;
					if (fd == sockfd)
						{
							len = sizeof(struct sockaddr_in);
							if ((clifd = accept(sockfd, (struct sockaddr*)&cli, &len)) == -1)
          			{
          				perror("socket error:");
          			  exit(EXIT_FAILURE);
          			}
      			  printf("New Connect From: %s\n", inet_ntoa(cli.sin_addr));
      			  pfd.fd = clifd;
      			  pfd.events = POLLOUT | POLLIN;
          		for(j = 0; j < 512; j++)
          		{
          			if (fds[j].fd != -1)
          				continue;
          			break;
          		}
          		fds[j] = pfd;
          		FDSIZE = clifd >= FDSIZE ? clifd + 1 : FDSIZE;
          	}
          else 
          	{
          		printf("ddddddd\n");
          		run(fd, fds, i);
          	}
       }
		}
		sleep(1);
	}
	close(sockfd);
}