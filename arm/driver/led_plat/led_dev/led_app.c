#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define LED_ON  _IO('L', 1)
#define LED_OFF _IO('L', 0)

int main()
{
	int fd = 0;
	if((fd = open("/dev/led", O_RDWR)) == -1)
		{
			perror("open error:");
			exit(EXIT_FAILURE);
		} 
	while(1)
	{
		sleep(1);
		ioctl(fd, LED_ON, 1);
		sleep(1);
		ioctl(fd, LED_OFF, 3);
		sleep(1);
		ioctl(fd, LED_ON, 4);
		sleep(1);
		ioctl(fd, LED_OFF, 2);
		sleep(1);
		ioctl(fd, LED_ON, 3);
		sleep(1);
		ioctl(fd, LED_OFF, 1);
		sleep(1);
		ioctl(fd, LED_ON, 2);
		sleep(1);
		ioctl(fd, LED_OFF, 4);
	}
	close(fd);
	return 0;
}