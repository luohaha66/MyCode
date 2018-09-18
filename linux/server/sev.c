#include "main.h"

#define port 6666

int server_init()
{
	int opt       = -1;
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);	//���������׽���
	if ( socket_fd < 0) {
		perror("socket:");	//��ӡ������Ϣ
		exit(-1);
	}
	
	struct sockaddr_in server;	//���屣��IP��ַ�Ͷ˿ںŵĽṹ�������InternetЭ���ַ�ṹ��
	
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));//���ö˿����ã�����˿ڱ�ռ������
	
	memset(&server, 0, sizeof(server));
	server.sin_family 		  = AF_INET;//PF_INET
	server.sin_port			    = htons(port);
	server.sin_addr.s_addr	= htonl(INADDR_ANY);//"127.0.0.1"				//��д������Ԫ����Ϣ��Ҳ����ͨ��Э�顢IP��ַ���˿ں�
	
	if (bind(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0){	//��������Ԫ����Ϣ�ʹ����õĶ˿ں�
		perror("bind:");
	}
	
	listen(socket_fd, 12);//���ü����׽��֣�����ͬһʱ���ܽ��ܵ��������������
	
	return socket_fd;	//�����׽��ָ����ú���
}

int wait_for_client_connect(int socket_fd)
{
	struct sockaddr_in client;
	int len = sizeof(client);
	memset(&client, 0, sizeof(client));
	
	int confd = accept(socket_fd, (struct sockaddr *)&client, &len);//�����ȴ��ͻ��˵����ӣ����ͻ������ӳɹ��Ժ󣬱���ͻ��˵�IP��ַ�Ͷ˿ںŵ��ṹ���� 	
	if (confd < 0){
		perror("accept:");
	} 
	else {//����ͻ������ӳɹ������ӡ���ӿͻ��˵�IP��ַ�Ͷ˿ں�
		printf("connection from %s, port %d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
	}
	return confd;
}
