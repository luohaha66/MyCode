#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
	int shmid = 0;
	char* p = NULL;
	key_t key = ftok(".", 'm');
	if ((shmid = shmget(key, 512, IPC_CREAT | 0666)) == -1)
		{
			perror("shmget error");
			exit(EXIT_FAILURE);
		}
	if ( (p = (char*)shmat(shmid, NULL, 0)) == (char*)-1)
		{
			perror("shmat error");
			goto error;
		}
	while (1)
	{
		fgets(p, 128, stdin);	
		if (strcmp(p, "quit\n") == 0)
			goto error1;
	}
error:
	shmctl(shmid, IPC_RMID, NULL);
error1:
	shmdt(&shmid);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}