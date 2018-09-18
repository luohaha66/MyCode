#include "main.h"

void *read_request(void *arg)//�ͻ����߳�ִ�к���
{
	pthread_mutex_t mutex;//���廥����������
	
	pthread_mutex_init(&mutex, NULL);//��ʼ����
	
	
	int confd = *(int *)arg;//���βν����������͵�ת��
	int n     = 0;
	char buffer[128];	
	while(1){
		pthread_mutex_lock(&mutex);//����
		
		memset(buffer, 0, sizeof(buffer));//��buffer�������㣬��֤���ݵ�������
		
		n = read(confd, buffer, sizeof(buffer));
		if ( n < 0){//������ȡ�ͻ��˷��͵����ݣ��������ֵС���㣬���ȡʧ��
			perror("read:");
			exit(-1);
		}
		else if (n > 0)
			{
				printf("receive data is %s \n", buffer);
			}
			
		else 
			{
				pthread_mutex_unlock(&mutex);//����
				break;
			}
		pthread_mutex_unlock(&mutex);//����
	}
	pthread_exit((void *)0);
}
