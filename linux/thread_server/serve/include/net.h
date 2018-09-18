#ifndef __NET_H__
#define __NET_H__

#include <netinet/in.h>

#include "protocol.h"

#define DEF_TCP_SRV_PORT 19868


struct tcp_srv
{
	int 	sfd;
	int		epfd;
	void* arg; 
};

struct tcp_cli
{
	int   cfd;
	char* buf;
	int   len;
	
	struct sockaddr_in cli_addr;
	struct evnet_ext*  ev_rx;
	struct evnet_ext*  ev_tx;
	struct tcp_srv*    srv; 
	 
	unsigned char req[FRAME_MAX_SZ];
	unsigned char rsp[FRAME_MAX_SZ + VID_FRAME_MAX_SZ ];
};

#endif