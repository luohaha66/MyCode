#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <error.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	pid_t pid = fork();
	if (pid == -1)
		{
			perror("fork error");
			exit(-1);
		}
	else if (pid > 0)
		exit(0);
	else if (pid == 0)
		{
			setsid();
			chdir("/");
			umask(0);
			int f = 0;
			int n  = getdtablesize();
			while (f < n)
				close(f++);
			int fd = open("/home/ha/exercise/c_advanced_pro/processus/1.txt", 
			O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (fd == -1)
				{
					perror("open error");
					exit(-1);
				}
			while (1)
			{
				write(fd, "hello world!\n", 13);
				sleep(1);
			}
			close(fd);
			exit(0);
		}
	return 0;
}