#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
void myfun(int sig)
{
if(sig=SIGINT)
 printf("got sigint\n");
else if(sig=SIGQUIT)
printf("sigquit got\n");
}
int main(int argc,char *argv[])
{
printf("waiting for.....\n");
 signal(SIGINT,myfun);
signal(SIGQUIT,myfun);
pause();
return 0;
}
