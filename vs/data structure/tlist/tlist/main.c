#include "tlist.h"


void myprintf(tlist* head)
{
	printf(" %d ", head->data);
}

int main()
{
	int i = 0;
	tlist* list = create_list();
	for (i = 0; i < 10; i++)
	{
		insert_by_pos(list, i, i);
	}
	display(list, myprintf);
	change_data_bydata(list, 9, 100);
	display(list, myprintf);
	return 0;
}