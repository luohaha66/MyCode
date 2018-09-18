#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

int i = 0;
int j = 0;
pthread_mutex_t lock;

void* func(void* arg)
{
	while (1)
	{
		pthread_mutex_lock(&lock);
		printf("i = %d, j = %d\n", i, j);
		usleep(5000);
		pthread_mutex_unlock(&lock);
	}
}

int main()
{
	pthread_t tid;
	int a = 0;
	if (pthread_mutex_init(&lock, NULL) != 0)
		{
			perror("pthread_mutex_init error:");
			exit(-1);
		}
	if (pthread_create(&tid, NULL, func, NULL) != 0)
		{
			perror("pthread_create error:");
			exit(-1);
		}
	while(1)
	{
		pthread_mutex_lock(&lock);
		a++;
		i = a;
		j = a;
		usleep(5000);
		pthread_mutex_unlock(&lock);
	}
	return 0;
}