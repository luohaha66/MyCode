#include "ls.h"

int main(int argc, char* argv[])
{
	int i = 1;
	if(argc == 1)
		{
			my_lsfile("./");
		}
	else
		{
			if ((!(strcmp(argv[1], "-l"))) && (argv[2] == NULL))
				my_opendir("./");
			else
				while(++i < argc)
				{
					get_file_info(argv[i]);
				}
		}
	return 0;
}