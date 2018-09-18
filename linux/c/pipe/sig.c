#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func(int sig)
{
	if (sig == SIGINT)
		printf("=============\n");
	if (sig == SIGTSTP)
		printf("*************\n");
}

void fun1(int sig)
{
	printf("&&&&&&&&&&&&&&&\n");
}

void func2(int sig)
{
	if (sig == SIGINT)
		printf("$$$$$$$$$$$$$\n");
	if (sig == SIGTSTP)
		printf("############\n");
}
int main()
{
	void (*p)(int) = NULL;
	void (*f)(int) = NULL;
	alarm(5);
	signal(SIGALRM, fun1);
	int i = 0;
	p = signal(SIGINT, func);
	f = signal(SIGTSTP, func);
	while (1)
	{
		if (i == 5)
			{
				p = signal(SIGINT, func2);
				f = signal(SIGTSTP, func2);
			}
		if (i == 10)
			{
				p = signal(SIGINT, p);
				f = signal(SIGTSTP, f);
			}
		i++;
		printf("--------------\n");
		sleep(1);
	}
}
