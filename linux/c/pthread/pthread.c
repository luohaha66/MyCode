#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* func(void* arg)
{
	int i = 0;
	char* p = "hello world!";
	while(++i)
	{
		printf("-----------\n");
		sleep(1);
		if ( i == 5)
			pthread_exit((void*)p);
	}
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, func, NULL);
	int i = 0;
	void* p = NULL;
	while (++i)
	{
		printf("============\n");
		sleep(1);
		if ( i == 3)
			
			{
				pthread_join(tid, &p);
				printf("%s \n", (char*)p);
				pthread_cancel(tid);
				exit(0);
			}
	}
	return 0;
}