#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <string.h>

FILE* fp = NULL;
int len = 0;
char buf[50] = {0};
sem_t sem_r;
sem_t sem_w;

void* func(void* arg)
{
	while (1)
	{
		sem_wait(&sem_r);
		fseek(fp, -len, SEEK_CUR);
		printf("%s", fgets(buf, 50, fp));
		sem_post(&sem_w);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	if ((fp = fopen("./2.txt", "a+")) == NULL)
		{
			perror("fopen error:");
			exit(-1);
		}
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
		time_t ti;
		time(&ti);
		struct tm* p = localtime(&ti);
		fseek(fp, 0, SEEK_END);
		len = fprintf(fp, "%d-%d-%d %d:%d:%d\n", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday,
		p->tm_hour, p->tm_min, p->tm_sec);
		fflush(fp);
		sleep(1);
		sem_post(&sem_r);
	}
	fclose(fp);
	return 0;
}
