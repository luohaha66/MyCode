#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *clean(void *arg)
{
 printf("clean up: %s\n",(char *)arg);
return (void *)0;
}
void *pthread1(void *arg)
{
printf("pthread1 start.\n");
pthread_cleanup_push((void *)clean,"the firast clean:");
pthread_cleanup_push((void *)clean,"the second clean:");
printf("pyhread1 push.\n");
/* if(arg)
{
return (void*)0;
}
*/
pthread_cleanup_pop(1);
pthread_cleanup_pop(1);
return (void*)0;
}
void *pthread2(void *arg)
{
printf("pthread2 start:\n");
pthread_cleanup_push((void *)clean,"the firast clean:");
pthread_cleanup_push((void *)clean,"the second clean:");
printf("pthread2 push.\n");
if(arg)
{
pthread_exit((void *)0);
}
pthread_cleanup_pop(0);
pthread_cleanup_pop(0);
pthread_exit((void *)0);
}

int main(void)
{
pthread_t mpid1,mpid2;
void *tmp;
pthread_create(&mpid1,NULL,pthread1,(void *)1);
pthread_create(&mpid2,NULL,pthread2,(void *)1);
pthread_join(mpid1,&tmp);
pthread_join(mpid2,&tmp);
return 0;
}

