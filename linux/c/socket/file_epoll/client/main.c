#include "client.h"


int main(int argc, char* argv[])
{
	char buf[128] = {0};
	char cmd[128] = {0};
	int num = 0;
	int clifd = 0;
	char c = 'q';
	char b = 'l';
	struct sockaddr_in ser;
	struct sockaddr_in cli;
	if (argc != 2)
		{
			printf("You need to input the ip address\n");
			exit(EXIT_FAILURE);
		}
	if ((clifd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			perror("socket error:");
			exit(EXIT_FAILURE);
		}
	memset(&cli, 0, sizeof(struct sockaddr_in));
	cli.sin_family = AF_INET;
	cli.sin_port = htons(8888);
	cli.sin_addr.s_addr = inet_addr(argv[1]);
	
	if (connect(clifd, (struct sockaddr*)&cli, sizeof(struct sockaddr_in)) == -1)
		{
			perror("connect error:");
			exit(EXIT_FAILURE);
		}
	else
		printf("connect success\n");
	while(1)
	{
		fgets(buf, 128, stdin);
		if (strcmp(buf, "help\n") == 0)
			{
				printf("-------------------------- put: Upload Files ---------------------------\n");
			  printf("-------------------------- get: Download Files -------------------------\n");
			  printf("-------------------------- help: Get Help ------------------------------\n");
			  printf("-------------------------- quit: Exit ----------------------------------\n");
			}
		if (strcmp(buf, "quit\n") == 0)
			{
					write(clifd, &c, 1);
					exit(EXIT_SUCCESS);
			}
		if (strcmp(buf, "list\n") == 0)
			{
				memset(buf, 0, 512);
				write(clifd, &b, 1);
				read(clifd, buf, 512);
				printf("%s\n", buf);
			}
		sscanf(buf, "%[^ ]", cmd);
		handle(buf, cmd, clifd);
	}
}