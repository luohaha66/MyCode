#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
		return -1;
	char buf[30];
	size_t n = 0;
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL)
		perror("fopen error:");
	FILE* fc = fopen(argv[2], "w");
	if (fc == NULL)
		perror("fopen error");
	while (fread(buf, 1, 1, fp) && !feof(fp))
	{
		fwrite(buf, 1, 1, fc);
	}		
	fclose(fp);
	fclose(fc);
}