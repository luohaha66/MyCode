#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(int argc,char *argv[])
{
	int shimd,pid;
	char *p_addr,*q_addr;
	shimd=shmget(IPC_PRIVATE,1024,IPC_CREAT);
	pid=fork();
	if(pid!=0)
	{
		p_addr=shmat(shimd,0,0);
		memset(p_addr,'\0',sizeof(p_addr));
		strncpy(p_addr,argv[1],1024);
		wait(NULL);
		shmdt(p_addr);
		exit(0);
	}
	else
	{
		sleep(1);
		q_addr=shmat(shimd,0,0);
		printf("%s\n",q_addr);
		shmdt(q_addr);
		exit(0);
	}
	return 1;
}
