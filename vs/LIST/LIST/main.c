#include<stdio.h>
#include<malloc.h>
#include"list.h"

int main(int argc,char* argv[])
{
	Slist* mlist=Slist_creat(4);
	int i = 1;
	int j = 2;
	int k = 3;
	int z = 4;
	int b = 5;
	int ind = 0;
    Slist_insert(mlist, i, 0);
    Slist_insert(mlist, j, 0);
	Slist_insert(mlist, k, 0);
	Slist_insert(mlist, z, 0);
	Slist_insert(mlist, b, 0);
    for (ind = 0; ind< Slist_length(mlist);ind++)
	{
	printf("%d\n",(Slist_get(mlist, ind)));
	}
	printf("%d\n", Slist_length(mlist));
	printf("%d\n", Slist_capacity(mlist));
	Slist_delete(mlist, 2);
	for (ind = 0; ind< Slist_length(mlist); ind++)
	{
		printf("%d\n", (Slist_get(mlist, ind)));
	}
	printf("%d\n", Slist_length(mlist));
	printf("%d\n", Slist_capacity(mlist));
	Slist_destory(mlist);
}