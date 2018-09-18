#include "server.h"

void handle(char cmd, int clifd)
{
	int namesize = 0;
	int filesize = 0;
	int tmpsize = 0;
	int fd = 0;
	int num = 0;
	char filename[20] = {0};
	char buf[512] = {0};
	struct stat fileinfo;
	switch(cmd)
	{
		case 'd':
		{
			memset(buf, 0, 512);
			read(clifd, &namesize, 4);
			read(clifd, filename, namesize);
			filename[namesize] = '\0';
			if ((fd = open(filename, O_RDONLY)) == -1)
				{
					perror("download file error:");
					return;
				}
			if(stat(filename, &fileinfo) == -1)
				return;
			write(clifd, &(fileinfo.st_size), 4);
			while((num = read(fd, buf, 512)) != 0)
			{
				write(clifd, buf, num);
			}
			close(fd);
		}
		break;
		
		case 'u':
			{
				memset(buf, 0, 512);
				read(clifd, &namesize, 4);
				read(clifd, (void*)filename, namesize);
				filename[namesize] = '\0';
				if ((fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
					{
						perror("upload file error:");
						return;
					}
				read(clifd, &filesize, 4);
				while((num = read(clifd, buf, 512)) != 0)
				{
					write(fd, buf, num);
					tmpsize += num;
					if (tmpsize == filesize)
						break;
				}
				close(fd);
			}
		break;
		
		case 'l':
			{
			  DIR* d = opendir("./");
				struct dirent* p = NULL;
				memset(buf, 0, 512);
				while (( p = readdir(d)) != NULL)
        	{
        		if (p->d_name[0] == '.')
        			continue;
        		strcat(p->d_name, "  ");
        		strcat(buf, p->d_name);
        	}
        num = strlen(buf);
        write(clifd, buf, num);
        closedir(d);
			}
		break;
	}
}

void run(int arg)
{
	char cmd;
	while(1)
		{
			read(arg, &cmd, 1);
			if (cmd == 'q')
				{
					close(arg);
					exit(EXIT_SUCCESS);
					break;
				}
			else 
				{
					handle(cmd, arg);
				}
		}
		close(arg);
}

void handler()
{
	while(waitpid(-1, NULL, WNOHANG));
}