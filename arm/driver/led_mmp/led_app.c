#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

int fd = 0;
char* p = NULL;
int* gpcon = NULL;

void led_init()
{
	if((fd = open("/dev/led", O_RDWR)) == -1)
		{
			perror("open error:");
			exit(EXIT_FAILURE);
		} 
		
	p = (char*)mmap(NULL, 1024, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	if( p == MAP_FAILED)
		{
			perror("mmap error:");
			exit(EXIT_FAILURE);
		}
	gpcon = (int*)(p + 0xC40);
	*gpcon = 0x1 << 28;
}

void led_on()
{
	*(gpcon + 1) |= 0x1 << 7;
}

void led_off()
{
	*(gpcon + 1) &= ~(0x1 << 7);
}

int main()
{
	led_init();
	while(1)
	{
		usleep(200);
		led_on();
		usleep(200);
		led_off();
		sync();
	}
	munmap(p, 1024);
	close(fd);
	return 0;
}