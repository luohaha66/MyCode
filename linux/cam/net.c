#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>

#include "main.h"


void net_send(struct tcp_cli* tc, void* buf, int len)
{
	struct tcp_cli *c = (struct tcp_cli*)tc;
	struct tcp_srv *s = c->srv;
     
	
	epoll_del_event(s->epfd, c->ev_rx);
	
	c->buf = buf;
	c->len = len;
	
	epoll_add_event(s->epfd, c->ev_tx);
	
}

static void rx_app_handler(int fd, void* arg)
{
	unsigned char* pbuf;
	struct   tcp_cli* c = arg;
	int      res        = 0;
	pbuf                = &(c->req[0]);
	
	
	
	
	res = read(c->cfd, pbuf, FRAME_HDR_SZ);
	if(res == -1)
		{
			perror("read error:\n");
			exit(-1);
		}

	process_incoming(c);
}

static void tx_app_handler(int fd, void* arg)
{
	struct tcp_cli* c = arg;
	struct tcp_srv *s = c->srv;
  int    res        = 0;
  
	res = send(fd, c->buf, c->len, 0);
	if (res == -1)
		{
			perror("send error:\n");
			exit(-1);
		}
	
	if (res > 0) {
        c->len -= res;
        if (c->len == 0) {
            epoll_del_event(s->epfd, c->ev_tx);
            epoll_add_event(s->epfd, c->ev_rx);
        }
    } 
}

int build_ack(unsigned char* rsp, unsigned char type, 
							unsigned char id, unsigned char len, unsigned char* data)
{
		rsp[LEN_POS]  = len;
		rsp[CMD0_POS] = type;
		rsp[CMD1_POS] = id;
		memcpy(&rsp[DAT_POS], data, len);
		
		return (len + FRAME_HDR_SZ);
}


int net_sys_init()
{
	struct tcp_srv*    s;
	struct tcp_cli*    c;
	struct sockaddr_in srv_addr;
	struct sockaddr_in cli_addr;
	int    len = 0;
	s = calloc(1, sizeof(struct tcp_srv));
	c = calloc(1, sizeof(struct tcp_cli));
	
	s->epfd = srv_main->epfd;
	//1.初始化网络传输子系统(tcp)
	//1.1创建socket
	if ((s->sfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			perror("socket error");	
			exit(-1);
		}
	
	//1.2初始化地址
	memset(&srv_addr, 0, sizeof(struct sockaddr_in));
	srv_addr.sin_addr.s_addr = INADDR_ANY;
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(DEF_TCP_SRV_PORT);
	
	//1.3绑定地址
	if ((bind(s->sfd, (struct sockaddr*)(&srv_addr), sizeof(struct sockaddr))) == -1)
		{
			perror("bind error");	
			exit(-1);
		}
	
	//1.4监听
	if (listen(s->sfd, 5) == -1)
	{
	    perror("listen error");
	    exit(-1);
	}	
	
	//1.5等待链接
	len = sizeof(struct sockaddr);
	if ((c->cfd = accept(s->sfd, (struct sockaddr*)(&cli_addr), &len)) == -1)
		{
			perror("accept error!");
			exit(-1);
		}
		
	memcpy(&(c->cli_addr), &cli_addr,len);
	c->srv = s;
	
	//2.将传输子系统中的事件加入EPOLL
	c->ev_rx = (struct evnet_ext*)epoll_event_create(c->cfd, EPOLLIN, rx_app_handler, c);
	c->ev_tx = (struct evnet_ext*)epoll_event_create(c->cfd, EPOLLOUT, tx_app_handler, c);
	
	epoll_add_event(c->srv->epfd, c->ev_rx);
	
	srv_main->srv = s;
	return 0;
}