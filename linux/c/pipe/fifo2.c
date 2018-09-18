#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>

void* func(void* arg)
{
	int fd = 0;
	int num = 0;
	char buf[128] = {0};
	if ((fd = open("./2", O_WRONLY)) == -1)
		{
			perror("open error:");
			exit(EXIT_FAILURE);
		}
	while(1)
	{
		num = read(0, buf, 128);
		write(fd, buf, num);
	}
}


int main()
{
	pthread_t tid;
	int fd = 0;
	int num = 0;
	char buf[128] = {0};
	if ((fd = open("./1", O_RDONLY)) == -1)
		{
			perror("open error:");
			exit(EXIT_FAILURE);
		}
	if (pthread_create(&tid, NULL, func, (void*)fd) != 0)
		{
			perror("pthread_create error:");
			exit(EXIT_FAILURE);
		}
	while(1)
	{
		if (read(fd, buf, 128) == 0)
			exit(EXIT_FAILURE);
		printf("from 1:%s", buf);
		memset(buf, 0, 128);
	}
}