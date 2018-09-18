#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/un.h>

int main()
{
	int sockfd = 0;
	int clifd = 0;
	int len = 0;
	int opt = 1;
	char buf[128] = {0};
	struct sockaddr_un ser;
	struct sockaddr_un cli;
	if ((sockfd = socket(AF_LOCAL, SOCK_STREAM, 0)) == -1)
		{
			perror("socket error:");
			exit(EXIT_FAILURE);
		}
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
	memset(&ser, 0, sizeof(ser));
	ser.sun_family = AF_LOCAL;
	strcpy(ser.sun_path, "/home/ha/exercise/c_advanced_pro/socket/unix/socket");
	unlink("/home/ha/exercise/c_advanced_pro/socket/unix/socket");
	if (bind(sockfd, (struct sockaddr*)&ser, sizeof(ser)) == -1)
		{
			perror("bind error:");
			exit(EXIT_FAILURE);
		}
	listen(sockfd, 5);
	len = sizeof(struct sockaddr_un);
	while(1)
	{
		if ((clifd = accept(sockfd, (struct sockaddr*)&cli, &len)) == -1)
			{
				perror("socket error:");
			  exit(EXIT_FAILURE);
			}
		while(1)
		{
			read(clifd, buf, 128);
			printf("%s", buf);
			memset(buf, 0, 128);
		}
	}
	return 0;
}