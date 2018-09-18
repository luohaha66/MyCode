#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	char* argv[] = {"ls", NULL};
	char* envp[] = {NULL};
	pid_t pid = fork();
	pid_t tem = 0;
	if (pid == -1)
		{
			perror("fork error");
			return -1;
		}
	else if (pid > 0)
		{
			int a;
			/*tem = wait(&a);*/
			tem = waitpid(-1, &a, 0);
			printf ("the child pid is %d, exit status is %d \n", (int)tem, a);
			printf ("the child process is end\n");
			exit(0);
		}
	else if (pid == 0)
		{
			/*if (execl("/bin/ls", "ls", NULL) == -1)
				{
					perror("execl error");
					exit(-1);
				}
			if (execv("/bin/ls", argv) == -1)
				{
					perror("execv error");
					exit(-1);
				}
			if (execle("/bin/ls", "ls", NULL, envp) == -1)
				{
					perror("execle error");
					exit(-1);
				}
			if (execve("/bin/ls", argv, envp) == -1)
				{
					perror("execve error");
					exit(-1);
				}
			if (execlp("ls", "ls", NULL) == -1)
				{
					perror("execlp error");
					exit(-1);
				}
			if (execvp("ls", argv) == -1)
				{
					perror("execvp error");
					exit(-1);
				}
			if (execvpe("ls", argv, envp) == -1)
				{
					perror("execvpe error");
					exit(-1);
				}*/
			int i = 5;
			int fd = open("./1.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (fd == -1)
				{
					perror("open error");
					exit(-1);
				}
			while (i--)
			{
				write(fd, "hello world!\n", 13);
				sleep(1);
			}
			close(fd);
			exit(0);
		}
		return 0;
}