#include <stdio.h>
#include <sys/epoll.h>
#include <stdlib.h>
#include <string.h>
#include <asm/types.h>

#include "net.h"

struct server
{
    int 		epfd; //指向epoll
    struct  cam *cam; //指向采集子系统
    struct  tcp_srv *srv; //指向传输子系统
    struct  cfg* cfg; //指向配置子系统
};

/*struct event_ext* epoll_event_create(int fd, uint32_t type, void (*handler)(int fd,void* arg), void* arg);
int epoll_add_event(int epfd,struct event_ext* ev);
int epoll_del_event(int epfd,struct event_ext* ev);
void epoll_event_free(struct event_ext * ev);
void net_send(struct tcp_cli* tc, void* buf, int len);
static void rx_app_handler(int fd, void* arg);
static void tx_app_handler(int fd, void* arg);
int build_ack(unsigned char* rsp, unsigned char type, 
							unsigned char id, unsigned char len, unsigned char* data);
int net_sys_init();
void handle_jpeg_proc(void* p, size_t size, void* arg);
void cam_handler(int fd, void* arg);
struct v4l2_dev* v4l2_init();
void v4l2_start_capture(struct v4l2_dev* v);
struct cam* cam_sys_init();
void cam_get_fmt(struct cam *v, __u8* data);
size_t cam_get_trans_frame(struct cam* v, __u8* data);*/
__u8 process_incoming(struct tcp_cli* c);
struct server* srv_main;