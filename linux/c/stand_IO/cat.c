#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
		return -1;
	char buf[30];
	int i = 0;
	while (++i < argc)
	{
		FILE* fp = fopen(argv[i], "r");
		if (fp == NULL)
		perror("fopen error:");
		while (fread(buf, 1, 1, fp) && !feof(fp))
		{
			fwrite(buf, 1, 1, stdout);
		}		
		fclose(fp);
		printf("\n");
	}
}