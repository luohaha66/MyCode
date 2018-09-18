#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
	int sockfd = 0;
	int len = 0;
	int opt = 1;
	char c;
	char buf[128] = {0};
	char dat[128] = {0};
	struct sockaddr_in ser;
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
		{
			perror("socket error:");
			exit(EXIT_FAILURE);
		}
	setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(int));
	memset(&ser, 0, sizeof(ser));
	ser.sin_family = AF_INET;
	ser.sin_port = htons(8888);
	ser.sin_addr.s_addr = inet_addr("224.10.10.10");
	
	len = sizeof(ser);
	fgets(buf, 128, stdin);
	sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&ser, len);
	while(1)
	{
		if  (strlen(buf) == 2)
			c = buf[0];
		while (c == 's')
			{
				memset(buf, 0, 128);
				fgets(buf, 128, stdin);
				sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&ser, len);
				if((buf[0] == 'r') && (strlen(buf) == 2))
					{
						c = 'r';
						break;
					}
			}
		while (c == 'r')
		{
				memset(buf, 0, 128);
				recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&ser, &len);
				if((buf[0] == 's') && (strlen(buf) == 2))
					{
						c = 's';
						break;
					}
				printf("%s", buf);
		}
	}
}