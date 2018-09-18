#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
static int a=1;
/*
void *mythread(void)
{
 int i;
for(i=0;i<3;i++)
{
 printf("this is the first pthread\n");
 sleep(1);
}
}
void *mythread1(void)
{
 int i;
for(i=0;i<3;i++)
{
 printf("this is the first pthread\n");
 sleep(1);
}
}
int main()
{
pthread_t id1,id2;
pthread_create(&id1,NULL,(void*)mythread,NULL);
pthread_create(&id2,NULL,(void*)mythread1,NULL);
pthread_join(id1,NULL);
pthread_join(id2,NULL);
return 0;
}
*/
void *creat(void *arg)
{
printf("new pthread\n");
printf("the pthread id is %u\n",(unsigned int)pthread_self());
printf("the process id is %d\n",getpid());
return (void*)0;
}
int main(void)
{
// int a=5; 
pthread_t tpid;
int i;
pthread_create(&tpid,NULL,creat,(void*)(i));
 pthread_join(tpid,NULL);
printf("the process inthe main id is %d",getpid());
return 0;
}











