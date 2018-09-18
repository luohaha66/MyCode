#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

typedef struct msgbuf{
	long type;
	char text[128];
}msg;

int main()
{
	key_t key;
	msg buff[2];
	int len = sizeof(struct msgbuf) - sizeof(long);
	buff[0].type = 100;
	buff[1].type = 200;
	int msqid = 0;
	if ((key = ftok(".", 'q')) == -1)
		{
			perror("ftok error");
			exit(EXIT_FAILURE);
		}
	if ((msqid = msgget(key, IPC_CREAT | 0666)) == -1)
		{
			perror("ftok error");
			exit(EXIT_FAILURE);
		}
	while (1)
	{
		fgets(buff[1].text, 128, stdin);
		if (msgsnd(msqid, &buff[1], len, 0) == -1)
			{
					perror("msgsnd error");
			    goto error;
			}
		if (strcmp(buff[1].text, "quit\n") == 0)
			goto error;
			
		/*if (msgrcv(msqid, &buff[0], len, buff[0].type, 0) == -1)
			{
					perror("msgsnd error");
			    goto error;
			}
		if (strcmp(buff[0].text, "quit\n") == 0)
			goto error;
		printf("%s", buff[0].text);*/
	}
	
error:
	msgctl(msqid, IPC_RMID, NULL);
	return 0;
}