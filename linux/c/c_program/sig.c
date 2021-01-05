#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void fun(int sig)
{
	printf("if you want to quit,plesae try SIGQUIT\n");
}
int main(void)
{
	sigset_t set;
	struct sigaction ac1,ac2;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigaddset(&set,SIGQUIT);
	sigprocmask(SIG_BLOCK,&set,NULL);
	printf("blocked\n");
	sleep(3);
	sigprocmask(SIG_UNBLOCK,&set,NULL);
	printf("unblocked\n");
	while(1)
	{
		if(sigismember(&set,SIGINT))
		{
			sigemptyset(&ac1.sa_mask);
			ac1.sa_handler=fun;
			sigaction(SIGINT,&ac1,NULL);
		}
		else if(sigismember(&set,SIGQUIT))
		{
			sigemptyset(&ac2.sa_mask);
			ac2.sa_handler=SIG_DFL;
			sigaction(SIGTERM,&ac2,NULL);
		}
	}
}
