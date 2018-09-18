#include "client.h"

void download(char* name, int clifd)
{
	char buf[512] = {0};
	int fd = 0;
	int num = 0;
	int filesize = 0;
	int tempsize = 0;
	int namesize = 0;
	char cmd = 'd';
	namesize = strlen(name);
	write(clifd, &cmd, 1);
	write(clifd, &namesize, 4);
	write(clifd, name, namesize);
	if((fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0666)) == -1)
		{
			perror("download file error");
			return;
		}
	read(clifd, &filesize, 4);
	while((num = read(clifd, buf, 512)) != 0)
	{
		write(fd, buf, num);
		tempsize += num;
		if (tempsize == filesize)
			break;
	}
	close(fd);
	printf("Download Finished\n");
}

void upload(char* name, int clifd)
{
	char buf[512] = {0};
	int fd = 0;
	int num = 0;
	int filesize = 0;
	int tempsize = 0;
	int namesize = 0;
	char cmd = 'u';
	struct stat fileinfo;
	namesize = strlen(name);
	write(clifd, &cmd, 1);
	write(clifd, &namesize, 4);
	write(clifd, (void*)name, namesize);
	if((fd = open(name, O_RDONLY)) == -1)
		{
			perror("download file error");
			return;
		}
	if(stat(name, &fileinfo) == -1)
				return;
	write(clifd, &(fileinfo.st_size), 4);
	while((num = read(fd, buf, 512)) != 0)
	{
		write(clifd, buf, num);
	}
	close(fd);
	printf("Upload Finished\n");
}

void handle(char* buf, char* cmd, int clifd)
{
	int i = 0;
	int j = 0;
	char name[128] = {0};
	if (strcmp(cmd, "get") == 0)
		{
			i = 4;
			j = 0;
			while(1)
				{
					if(buf[i] == '\n')
						break;
					name[j++] = buf[i++];
				}
			name[j] = '\0';
			download(name, clifd);
		}
	if (strcmp(cmd, "put") == 0)
		{
			i = 4;
			j = 0;
			while(1)
				{
					if(buf[i] == '\n')
						break;
					name[j++] = buf[i++];
				}
			name[j] = '\0';
			upload(name, clifd);
		}
}

