#include "main.h"

#define port 6666

int server_init()
{
	int opt       = -1;
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);	//创建网络套接字
	if ( socket_fd < 0) {
		perror("socket:");	//打印错误信息
		exit(-1);
	}
	
	struct sockaddr_in server;	//定义保存IP地址和端口号的结构体变量（Internet协议地址结构）
	
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));//设置端口重用，解决端口被占用问题
	
	memset(&server, 0, sizeof(server));
	server.sin_family 		  = AF_INET;//PF_INET
	server.sin_port			    = htons(port);
	server.sin_addr.s_addr	= htonl(INADDR_ANY);//"127.0.0.1"				//填写网络三元组信息，也就是通信协议、IP地址、端口号
	
	if (bind(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0){	//将网络三元组信息和创建好的端口号
		perror("bind:");
	}
	
	listen(socket_fd, 12);//设置监听套接字，允许同一时刻能接受的最大链接请求数
	
	return socket_fd;	//返回套接字给调用函数
}

int wait_for_client_connect(int socket_fd)
{
	struct sockaddr_in client;
	int len = sizeof(client);
	memset(&client, 0, sizeof(client));
	
	int confd = accept(socket_fd, (struct sockaddr *)&client, &len);//阻塞等待客户端的链接，当客户端链接成功以后，保存客户端的IP地址和端口号到结构体中 	
	if (confd < 0){
		perror("accept:");
	} 
	else {//如果客户端链接成功，则打印链接客户端的IP地址和端口号
		printf("connection from %s, port %d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
	}
	return confd;
}
