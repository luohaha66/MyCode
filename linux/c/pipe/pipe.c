#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd[2] = {0};
	char buf[128] = {0};
	int num = 0;
	pid_t pid;
	if (pipe(fd) == -1)
		{
			perror("pepe error:");
			exit(EXIT_FAILURE);
		}
	pid = fork();
	if (pid == -1)
		{
			perror("fork error:");
			exit(EXIT_FAILURE);
		}
	else if (pid > 0)
		{
			close(fd[0]);
			while (1)
			{
				num = read(0, buf, 128);
				write(fd[1], buf, num);
			}
			close(fd[1]);
		}
	else if (pid == 0)
		{
			close(fd[1]);
			while (1)
			{
				read(fd[0], buf, 128);
				printf("%s", buf);
				memset(buf, 0, 128);
			}
			close(fd[0]);
		}
}