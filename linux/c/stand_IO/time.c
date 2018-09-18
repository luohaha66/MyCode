#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
		{
			printf("you need to input filenane.\n");
			return -1;
		}
	int i = 1;
	int len = 0;
	char buf[30] = {0};
	FILE* f = fopen(argv[1], "a+");
	while(fgets(buf, 30, f))
	{
		len = strlen(buf);
		if (buf[len - 1] == '\n')
			i++;
	}
	while (1)
	 {
	 	time_t t;
	 	time(&t);
	 	struct tm* ti = NULL;
	 	ti = localtime(&t);
	 	fprintf(f, "%d: %d-%d-%d %d:%d:%d\n", i++, ti->tm_year + 1900, 
	 	ti->tm_mon + 1, ti->tm_mday, ti->tm_hour, ti->tm_min, ti->tm_sec);
	 	fflush(f);
	 	sleep(1);
	 }
	 fclose(f);
}