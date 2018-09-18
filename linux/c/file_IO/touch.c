#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int i = 0;
	int fd = 0;
	while (++i < argc)
	{
			fd = open(argv[i], O_CREAT | O_RDWR | O_EXCL | O_TRUNC, 0644);
			if ( fd == -1)
				{
					printf("Error\n");
					return -1;
				}
			close(fd);
	}
	return 0;
}