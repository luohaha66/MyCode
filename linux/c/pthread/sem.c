#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

int fd = 0;
int len = 0;
char buf[50] = {0};
sem_t sem_r;
sem_t sem_w;

void* func(void* arg)
{
	while (1)
	{
		sem_wait(&sem_r);
		if ((fd = open("./1.txt", O_CREAT | O_RDONLY, 0644) == -1))
		{
			perror("open error:");
			exit(-1);
		}
		lseek(fd, -len, SEEK_END);
		read(fd, buf, len);
		printf("%s",buf);
		memset(buf, 0, 50);
		close(fd);
		sem_post(&sem_w);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	if (sem_init(&sem_r, 0, 0) != 0)
		{
			perror("sem_init error:");
			exit(-1);
		}
	if (sem_init(&sem_w, 0, 1) != 0)
		{
			perror("sem_init error:");
			exit(-1);
		}
	if (pthread_create(&tid, NULL, func, NULL) != 0)
		{
			perror("pthread_create error:");
			exit(-1);
		}
	
	while (1)
	{
		sem_wait(&sem_w);
		if ((fd = open("./1.txt", O_CREAT | O_RDWR | O_APPEND , 0644) == -1))
		{
			perror("open error:");
			exit(-1);
		}
		time_t ti;
		time(&ti);
		struct tm* p = localtime(&ti);
		len = sprintf(buf, "%d-%d-%d %d:%d:%d\n", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday,
		p->tm_hour, p->tm_min, p->tm_sec);
		write(fd, buf, len);
		close(fd);
		sleep(1);
		sem_post(&sem_r);
	}
	return 0;
}
