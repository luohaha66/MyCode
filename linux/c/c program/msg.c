#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msgbuf
{
 long mtype;
char mtext[1024];
}msg;
int main()
{
 key_t key;
int msqid;
key=ftok("/root/mymsg",1);
msqid=msgget(key,IPC_CREAT|0666);
msg.mtype=getpid();
sprintf(msg.mtext,"I LOVE YOU");
msgsnd(msqid,&msg,sizeof(msg.mtext),IPC_NOWAIT);
memset(msg.mtext,0,sizeof(msg.mtext));
msgrcv(msqid,&msg,sizeof(msg.mtext),msg.mtype,IPC_NOWAIT);
printf("%s\n",msg.mtext);
// msgctl(msqid,IPC_RMID,NULL);
system("ipcs -q");
}
