#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define ADC_ON  _IO('L', 1)


int main()
{
	int fd = 0;
	if((fd = open("/dev/adc", O_RDWR)) == -1)
		{
			perror("open error:");
			exit(EXIT_FAILURE);
		} 
	close(fd);
	return 0;
}