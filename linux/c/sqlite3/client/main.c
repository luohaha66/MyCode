#include "client.h"


int main(int argc, char* argv[])
{
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
	login_or_register(clifd);
	while(1)
	{
		search_word(clifd);
	}
}