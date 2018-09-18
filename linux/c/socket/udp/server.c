#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main()
{
	int sockfd = 0;
	int len = 0;
	char buf[128] = {0};
	char dat[128] = {0};
	char c;
	struct sockaddr_in ser;
	struct sockaddr_in cli;
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
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
			perror("bind error");
			exit(EXIT_FAILURE);
		}
	recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&cli, &len);
	while(1)
	{
		if  (strlen(buf) == 2)
			c = buf[0];
		while (c == 's')
			{
				memset(buf, 0, 128);
				recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&cli, &len);
				if((buf[0] == 'r') && (strlen(buf) == 2))
					{
						c = 'r';
						break;
					}
				printf("%s", buf);
			}
		while (c == 'r')
		{
			memset(buf, 0, 128);
			fgets(buf, 128, stdin);
			sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&cli, len);
			if((buf[0] == 's') && (strlen(buf) == 2))
					{
						c = 's';
						break;
					}
		}
	}
}