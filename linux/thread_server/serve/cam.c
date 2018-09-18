#include <assert.h>
#include <getopt.h>           
#include <fcntl.h>            
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#include <linux/types.h>
#include <asm/types.h>      
#include <linux/videodev2.h>

#include "main.h"


struct buffers
{
	void*  start;
	size_t len;
};

struct cam
{
	struct v4l2_dev* v4_dev;
	struct buffers   tran_frm;
	__u32  tran_frm_max_size;
	int    len;
};

struct v4l2_dev
{
	int   fd;
	__u8  name[32];
	__u8  drv[16];
	void* arg;
	struct buffers* buff;
	struct event_ext* ev;
};

void handle_jpeg_proc(void* p, size_t size, void* arg)
{
	struct cam* v = arg;
	
	v->tran_frm.start = (void*)p;
	v->tran_frm.len   = size;
}

/*事件处理函数*/
void cam_handler(int fd, void* arg)
{
		 struct v4l2_buffer buf;
     struct v4l2_dev*   v = arg;
     
     /*帧出列*/
     buf.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
     buf.memory = V4L2_MEMORY_MMAP;
     ioctl(v->fd, VIDIOC_DQBUF, &buf);
     
     //保存图像
     handle_jpeg_proc(v->buff[buf.index].start, v->buff[buf.index].len, v->arg);
     
     /*buf入列*/
     ioctl(v->fd, VIDIOC_QBUF, &buf);
}

struct v4l2_dev* v4l2_init()
{
	struct v4l2_capability     cap;
	struct v4l2_dev*           v;
	struct v4l2_format         fmt;
  struct v4l2_requestbuffers req;
  struct v4l2_buffer         buf; 
  
  unsigned long i = 0;
		
	//1.初始化摄像头
	 v     = calloc(1,sizeof(struct v4l2_dev));
	 v->fd = open("/dev/video0", O_RDWR | O_NONBLOCK);
	
	 /*获取驱动信息*/
	 ioctl (v->fd, VIDIOC_QUERYCAP, &cap);
	 if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE))
	 	{
	 		printf("this is not a video device \n");
	 		exit(0);
	 	}
	 	strcpy((char*)v->name, (char*)cap.card);
	 	strcpy((char*)v->drv, (char*)cap.driver);
	 
	/*设置图像格式*/
		 fmt.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
     fmt.fmt.pix.width       = 1280;
     fmt.fmt.pix.height      = 1024;
     fmt.fmt.pix.field       = V4L2_FIELD_INTERLACED;
     fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;

     ioctl(v->fd, VIDIOC_S_FMT, &fmt);
	
	/*申请图像缓冲区*/
		 req.count               = 4;
     req.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
     req.memory              = V4L2_MEMORY_MMAP;
     ioctl(v->fd, VIDIOC_REQBUFS, &req);
	
	// 把内核空间中的图像缓冲区映射到用户空间
		v->buff = calloc(4, sizeof (struct buffers));
		
    for (i = 0; i < req.count; ++i)
    {
           /*获取图像缓冲区的信息*/
           buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
           buf.memory      = V4L2_MEMORY_MMAP;
           buf.index       = i;
 
           ioctl(v->fd, VIDIOC_QUERYBUF, &buf); 
             
           v->buff[i].len = buf.length; 
           
           // 把内核空间中的图像缓冲区映射到用户空间
           v->buff[i].start = mmap(NULL ,    //通过mmap建立映射关系
                                        buf.length,
                                        PROT_READ | PROT_WRITE ,
                                        MAP_SHARED ,
                                        v->fd,
                                        buf.m.offset);
     }
     
	/*图像缓冲入队*/ 
	for (i = 0; i < 4; ++i)
       {
               buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
               buf.memory      = V4L2_MEMORY_MMAP;
               buf.index       = i; 
               ioctl(v->fd, VIDIOC_QBUF, &buf);
               
       }
     
	//2.注册事件到EPOLL
	v->ev = (struct event_ext*)epoll_event_create(v->fd, EPOLLIN, cam_handler, v);
	epoll_add_event(srv_main->epfd, v->ev);
	
	return v;
}

void v4l2_start_capture(struct v4l2_dev* v)
{
	enum v4l2_buf_type type;
	
	//开始捕捉图像数据  
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ioctl (v->fd, VIDIOC_STREAMON, &type);
}

struct cam* cam_sys_init()
{
	struct cam* cam  = calloc(1,sizeof(struct cam));
	//1.初始化采集子系统
	cam->v4_dev      = v4l2_init();
	cam->v4_dev->arg = cam;
	
	//开始采集
	v4l2_start_capture(cam->v4_dev);
	
	return cam;
}

void cam_get_fmt(struct cam *v, __u8* data)
{
	__u32 fmt = V4L2_PIX_FMT_MJPEG;
	memcpy(data, &fmt, 4);
}

size_t cam_get_trans_frame(struct cam* v, __u8* data)
{
	memcpy(data, v->tran_frm.start, v->tran_frm.len);
	return v->tran_frm.len;
}

__u8 process_incoming(struct tcp_cli* c)
{
	struct cam* v   = srv_main->cam;
	__u8   id       = c->req[CMD1_POS];
	__u8   status   = ERR_SUCCESS;
	int    pos      = 0;
	size_t size     = 0;
	__u8   data[FRAME_DAT_MAX];

	__u8*  rsp      = c->rsp;
	
	switch (id)
	{
		case  REQUEST_ID(VID_GET_FMT): //VID_GET_FMT
			//获取图像格式
			cam_get_fmt(v, data);
			//构造返回数据
			build_ack(rsp, ((TYPE_SRSP) << TYPE_BIT_POS | (SUBS_VID)), id, 4, data);
			//发送返回数据
			net_send(c, rsp, 4 + FRAME_HDR_SZ);
		break;
			
		case  REQUEST_ID(VID_REQ_FRAME):  //VID_REQ_FRAME
			pos = FRAME_HDR_SZ + 4;
			//获取一帧图像
			size = cam_get_trans_frame(v, &rsp[pos]);
			//构造返回数据
			build_ack(rsp, ((TYPE_SRSP) << TYPE_BIT_POS | (SUBS_VID)), id, 4, (__u8*)(&size));
			//发送返回数据
			net_send(c, rsp, pos + size);
		break;
			
		default:
			 status = ERR_CMD_ID;
		break;
	}
	
	 return status;
}