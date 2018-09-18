#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define PWM_ON  _IO('L', 1)
#define PWM_OFF _IO('L', 0)

int main()
{
	int fd = 0;
	if((fd = open("/dev/pwm", O_RDWR)) == -1)
		{
			perror("open error:");
			exit(EXIT_FAILURE);
		} 
	while(1)
	{
		ioctl(fd, PWM_ON, 0);
		sleep(1);
		ioctl(fd, PWM_OFF, 0);
		sleep(1);
	}
	close(fd);
	return 0;
}