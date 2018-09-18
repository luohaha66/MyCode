#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <sys/shm.h>

#define SW 0
#define SR 1

typedef union semun{
	int val;
	struct semid_ds* buf;
	unsigned short* array;
}sem;

int main()
{
	int semid = 0;
	int shmid = 0;
	char* p = NULL;
	key_t key = ftok(".", 's');
	if ((shmid = shmget(key, 512, IPC_CREAT | 0666)) == -1)
		{
			perror("shmget error");
			exit(EXIT_FAILURE);
		}
		
	if ((semid = semget(key, 2, IPC_CREAT | IPC_EXCL | 0666)) == -1)
		{
			if (errno == EEXIST)
				{
					if (semid = semget(key, 2, 0666) == -1)
						{
							perror("semget error");
			        exit(EXIT_FAILURE);
						}
				}
			else 
			{
				perror("semget error");
			  exit(EXIT_FAILURE);
			}
		}
	else 
	{
		sem semw;
		semw.val = 0;
		semctl(semid, SW, SETVAL, &semw);
		
		sem semr;
		semr.val = 0;
		semctl(semid, SR, SETVAL, &semr);
	}
	
	if ( (p = (char*)shmat(shmid, NULL, 0)) == (char*)-1)
		{
			perror("shmat error");
			goto error;
		}
	
	while(1)
	{
		struct sembuf sr;
		sr.sem_num = SR;
		sr.sem_op = -1;
		sr.sem_flg = SEM_UNDO;
		semop(semid, &sr, 1);
		if (strcmp(p, "") != 0)
			fputs(p, stdout);
		if (strcmp(p, "quit\n") == 0)
			goto error1;
			
		struct sembuf sw;
		sw.sem_num = SW;
		sw.sem_op = 1;
		sw.sem_flg = SEM_UNDO;
		semop(semid, &sw, 1);
	}

error:
	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, 0, IPC_RMID);
	semctl(semid, 1, IPC_RMID);
error1:
	shmdt(&shmid);
	semctl(semid, 0, IPC_RMID);
	semctl(semid, 1, IPC_RMID);
	shmctl(shmid, IPC_RMID, NULL);
}