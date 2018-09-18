#include "main.h"



int main()
{
	pthread_t tid;
	int *temp;
	
	int socket_fd = server_init();//�������ĳ�ʼ��
	if (socket_fd < 0){
		exit(-1);
	}
	
	while(1){	
		int confd = wait_for_client_connect(socket_fd);//���÷�װ�ĺ������ȴ��ͻ��˵�����
		if (confd < 0){
			exit(-1);
		}
		temp = malloc(sizeof(int));//Ϊָ�뿪�ٿռ�
		*temp = confd;
		if (pthread_create(&tid, NULL, read_request, temp) < 0){//������һ���ͻ��˺�Ϳ���һ���̣߳���ר�Ŵ���ͻ�����������
			perror("create thread failed");
			continue;
		}
	}
}