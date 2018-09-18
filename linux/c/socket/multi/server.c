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
	int opt = 1;
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
	struct ip_mreqn mrq;
	memset(&mrq, 0, sizeof(mrq));
	mrq.imr_multiaddr.s_addr = inet_addr("224.10.10.10");
	mrq.imr_address.s_addr = INADDR_ANY;
	setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void*)&mrq, sizeof(mrq));
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
	setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(int));
	memset(&ser, 0, sizeof(ser));
	ser.sin_family = AF_INET;
	ser.sin_port = htons(8888);
	ser.sin_addr.s_addr = inet_addr("0.0.0.0");
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