#include "main.h"

void *read_request(void *arg)//客户端线程执行函数
{
	pthread_mutex_t mutex;//定义互斥锁的名字
	
	pthread_mutex_init(&mutex, NULL);//初始化锁
	
	
	int confd = *(int *)arg;//将形参进行数据类型的转换
	int n     = 0;
	char buffer[128];	
	while(1){
		pthread_mutex_lock(&mutex);//加锁
		
		memset(buffer, 0, sizeof(buffer));//将buffer数组清零，保证数据的完整性
		
		n = read(confd, buffer, sizeof(buffer));
		if ( n < 0){//阻塞读取客户端发送的数据，如果返回值小于零，则读取失败
			perror("read:");
			exit(-1);
		}
		else if (n > 0)
			{
				printf("receive data is %s \n", buffer);
			}
			
		else 
			{
				pthread_mutex_unlock(&mutex);//解锁
				break;
			}
		pthread_mutex_unlock(&mutex);//解锁
	}
	pthread_exit((void *)0);
}
