#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#include "main.h"

struct event_ext
{
	int      fd;
	bool     epolled;
	uint32_t events;
	void*    arg;
	void (*handler)(int fd,void* arg);
	
};

struct event_ext* epoll_event_create(int fd, uint32_t type, void (*handler)(int fd,void* arg), void* arg)
{
	struct event_ext* e = calloc(1, sizeof(struct event_ext));
	
	e->fd      = fd;
	e->events  = type;
	e->handler = handler;
	e->arg     = arg;
	
	return e;
}

int epoll_add_event(int epfd,struct event_ext* ev)
{
	//1.创建一个事件结构
	struct epoll_event epv;
	int op = 0;
	
	//2.初始化epoll_event(将附加结构挂载到epoll_event)
	epv.data.ptr = ev;
	epv.events   = ev->events;
	
	if(ev->epolled)
		{
			op = EPOLL_CTL_MOD;
		}
	else
		{
			op = EPOLL_CTL_ADD;
			ev->epolled = true;
		}
	
	//3.将epoll_event加入epoll
	epoll_ctl(epfd,op,ev->fd,&epv);
	return 0;
}

int epoll_del_event(int epfd,struct event_ext* ev)
{
	epoll_ctl(epfd,EPOLL_CTL_DEL,ev->fd,NULL);
	ev->epolled = false;
	return 0;
}

void epoll_event_free(struct event_ext * ev)
{
    struct event_ext *e = ev; 
    free(e);
}

int main()
{
	struct epoll_event events[512];
	struct event_ext* e;
	uint32_t event;
	srv_main = calloc(1, sizeof(struct server));
	int fds  = 0;
	int i    = 0;

	//1.创建epoll
	srv_main->epfd = epoll_create(512);
	
	//2.加入等待事件
	srv_main->cam  = (struct cam*)cam_sys_init();
	srv_main->srv  = (struct tcp_srv*)net_sys_init();
	
	//3.等待事件发生并处理
	while (1)
	{
		fds = epoll_wait(srv_main->epfd, events, 512, 1000);
		
		for (i = 0 ; i < fds ; i++)
		{
			event = events[i].events;
			e     =  events[i].data.ptr;
			if ((event & EPOLLIN) && (e->events & EPOLLIN))
				{
					//处理 
					e->handler(e->fd,e->arg);
				}
				
			if ((event & EPOLLOUT) && (e->events & EPOLLOUT))
				{
					//处理
					e->handler(e->fd,e->arg);
				}
			
			if ((event & EPOLLERR) && (e->events & EPOLLERR))
				{
					//处理
					e->handler(e->fd,e->arg);
				}
		}
	}

	return -1;
	
}