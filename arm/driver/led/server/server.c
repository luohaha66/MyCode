#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define LED_ON 1
#define LED_OFF 0

void run(int clifd)
{
	char buf[10] = {0};
	int fd = 0;
	unsigned char c = '5';
	unsigned int id = 0;
	if ((fd = open("/dev/led", O_RDWR)) == -1)
		{
			perror("open error");
			exit(EXIT_FAILURE);
		}
	while(1)
	{
		read(clifd, &c, 1);
		read(clifd, buf, 10);
		id = c - '0';
		if(strcmp(buf, "ledon") == 0)
			{
				ioctl(fd, LED_ON, id);
			}
		if(strcmp(buf, "ledoff") == 0)
			{
				ioctl(fd, LED_OFF, id);
			}
		memset(buf, 0, 10);
	}
}

int main()
{
	int len = 0;
	int num = 0;
	int sockfd = 0;
	int clifd = 0;
	int opt = 1;
	pid_t pid;
	struct sockaddr_in ser;
	struct sockaddr_in cli;
	char buf[128] = {0};
	char name[20] = {0};
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
				if ((pid = fork()) == -1)
    			{
    				perror("fork error:");
    			  exit(EXIT_FAILURE);
    			}
    		if (pid > 0)
    			{
    				close(clifd);
    			}
    		if (pid == 0)
    			{
    				close(sockfd);
    				run(clifd);
    			}
			}
	}
	close(sockfd);
}