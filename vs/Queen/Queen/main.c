#include<stdio.h>
#include "Queen.h"

int main(int argc, char* argv[])
{
	Queen* queen = Queen_creat();
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		Queen_insert(queen, i);
		printf("%d\n", Queen_del(queen));
	}
	Queen_destory(queen);
	return 0;
}