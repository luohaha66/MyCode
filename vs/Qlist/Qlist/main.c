#include<stdio.h>
#include "Qlist.h"

int main(int argc, char* argv[])
{
	int i = 1;
	Qlist* list=Qlist_creat();
	for (i = 1; i <9 ; i++)
	{
		Qlist_insert(list, i, Qlist_length(list));
    }
	for (i = 0; i < Qlist_length(list); i++)
	{
		Qlist* p = QList_moveup_slider(list);
		printf("%d\n", p->data);
	}
	printf("\n");
	Qlist* z=Qlist_reset_slider(list);
	while (Qlist_length(list) > 0)
	{
		for (i = 1; i < 3; i++)
		{
			QList_moveup_slider(list);
		}
		printf("%d\n", list->slider->data);
		Qlist_delete_slider(list, list->slider->data);
	}
	Qlist_destory(list);
	return 0;
}
