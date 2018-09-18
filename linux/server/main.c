#include "main.h"



int main()
{
	pthread_t tid;
	int *temp;
	
	int socket_fd = server_init();//服务器的初始化
	if (socket_fd < 0){
		exit(-1);
	}
	
	while(1){	
		int confd = wait_for_client_connect(socket_fd);//调用封装的函数，等待客户端的链接
		if (confd < 0){
			exit(-1);
		}
		temp = malloc(sizeof(int));//为指针开辟空间
		*temp = confd;
		if (pthread_create(&tid, NULL, read_request, temp) < 0){//链接上一个客户端后就开辟一个线程，来专门处理客户端数据请求
			perror("create thread failed");
			continue;
		}
	}
}