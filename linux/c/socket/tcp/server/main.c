#include "server.h"

int main()
{
	int len = 0;
	int num = 0;
	int sockfd = 0;
	int clifd = 0;
	int opt = 1;
	struct sockaddr_in ser;
	struct sockaddr_in cli;
	char buf[128] = {0};
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			perror("socket error:");
			exit(EXIT_FAILURE);
		}
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
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
	while(1)
	{
		if ((clifd = accept(sockfd, (struct sockaddr*)&cli, &len)) == -1)
			{
				perror("socket error:");
			  exit(EXIT_FAILURE);
			}
		else 
			{
				printf("New Connect From: %s\n", inet_ntoa(cli.sin_addr));
				/*struct timeval tv;
				tv.tv_sec = 5;
				tv.tv_usec = 0;
				setsockopt(clifd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));*/
				run(clifd);
			}
	}
	close(sockfd);
}