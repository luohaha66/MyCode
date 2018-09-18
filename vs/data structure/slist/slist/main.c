#include "slist.h"

void myprint(slist* list, int j)
{
	printf(" %d ", list->list_data[j]);
}

int main()
{
	int i = 0;
	slist* list = creatslist();
	for (i = 0; i < 10; i++)
	{
		insert_data(list, i, i);
	}
	display(list, myprint);
	find_and_replace(list, 5, 100);
	display(list, myprint);
	return 0;
}

