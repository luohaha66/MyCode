#include "client.h"

void login_or_register(int clifd)
{
	char name[20] = {0};
	char pass[20] = {0};
	char a;
	printf("Did you need to register?(Y/N)\n");
	a = getchar();
	while((a != 'y') && (a != 'n'))
	a = getchar();
	while(a)
	{
		if (a == 'y')
		{
			write(clifd, &a, 1);
			printf("Please input your register name:\n");
			read(0, name, 20);
			write(clifd, name, strlen(name));
			printf("Please input your register passwd:\n");
			read(0, pass, 20);
			write(clifd, pass, strlen(pass));
			read(clifd, &a, 1);
			if (a == 'a')
				{
					printf("Register Successful!\n");
				  break;
				}
			else if (a == 'e')
				{
					printf("The user name is exist,please input again:\n");
					memset(name, 0, 20);
					memset(pass, 0, 20);
					a = 'y';
				}
			else
				{
					printf("Register failed,please try again\n");
					memset(name, 0, 20);
					memset(pass, 0, 20);
					a = 'y';
				}
		}
	if (a == 'n')
		{
			write(clifd, &a, 1);
			printf("Please input your login name:\n");
			read(0, name, 20);
			write(clifd, name, strlen(name));
			printf("Please input your login passwd:\n");
			read(0, pass, 20);
			write(clifd, pass, strlen(pass));
			read(clifd, &a, 1);
			if(a == 'b')
				{
					printf("Login Successful!\n");
					break;
				}
			else if (a == 'f')
				{
					printf("Login failed,please try again:\n");
					memset(name, 0, 20);
					memset(pass, 0, 20);
					a = 'n';
				}
		}
	}
	
}

void search_word(int fd)
{
	char buf[20] = {0};
	char inf[1024] = {0};
	char c;
LOOP:
	printf("PLease input the word you want to know:(q to exit, h to query history)\n");
	memset(buf, 0, 20);
	read(0, buf, 20);
	if (strcmp(buf, "q\n") == 0)
		{
			write(fd, buf, strlen(buf));
			close(fd);
			exit(EXIT_SUCCESS);
		}
	else if (strcmp(buf, "h\n") == 0)
		{
			write(fd, buf, strlen(buf));
			read(fd, inf, 1024);
			printf("History: %s \n", inf);
			memset(inf, 0, 1024);
			goto LOOP;
		}
	else 
	{
		write(fd, buf, strlen(buf));
		read(fd, &c, 1);
		if(c == 'b')
			{
				read(fd, inf, 1024);
				printf("%s\n",inf);
				memset(inf, 0, 1024);
			}
		if(c == 's')
			{
				printf("The word doesn't exist,please input again!\n");
			}
	}
}