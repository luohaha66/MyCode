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
	int len = 0;
	char buf[128] = {0};
	struct sockaddr_un ser;
	if ((sockfd = socket(AF_LOCAL, SOCK_STREAM, 0)) == -1)
		{
			perror("socket error:");
			exit(EXIT_FAILURE);
		}
	memset(&ser, 0, sizeof(ser));
	ser.sun_family = AF_LOCAL;
	strcpy(ser.sun_path, "/home/ha/exercise/c_advanced_pro/socket/unix/socket");
	len = sizeof(struct sockaddr_un);
	while(1)
	{
		if (connect(sockfd, (struct sockaddr*)&ser, len) == -1)
			{
				perror("connect error:");
			  exit(EXIT_FAILURE);
			}
		while(1)
		{
			fgets(buf, 128, stdin);
			write(sockfd, buf, strlen(buf));
			memset(buf, 0, 128);
		}
	}
	return 0;
}