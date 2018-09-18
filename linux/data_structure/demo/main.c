#include "lstack.h"
#include "qlist.h"

void myprintf(qlist* list)
{
	printf("%d ", list->data);
}


void methond1()
{
	qlist* list = createqlist();
	qlist* q = NULL;
	lstack* stack = create_lstack();
	int i = 0;
	int data = 0;
	if (list == NULL || stack == NULL)
	{
		printf("Error: create failde\n");
		return -1;
	}
	for (i = 0; i < 10; i++)
		insert_into_qlist(list, i, i);
	printf("The data before changing is:\n");
	ldisplay(list, myprintf);
	for (i = 0; i < 10; i++)
	{
		q = find_ele_bypos(list, i);
		lstack_push(stack, q->data);
	}
	for (i = 0; i < 10; i++)
	{
		data = lsatck_pop(stack);
		change_data_bypos(list, i, data);
	}
	printf("The data after changing is:\n");
	ldisplay(list, myprintf);
	destory_qlist(list);
	destory_lstack(stack);
}

void methond2()
{
	qlist* list = createqlist();
	int i = 0;
	int n = 0;
	if (list == NULL)
	{
		printf("Error: create failde\n");
		return -1;
	}
	for (i = 0; i < 10; i++)
		insert_into_qlist(list, i, i);
	printf("The data before changing is:\n");
	ldisplay(list, myprintf);
	qlist* q = list->next;
	qlist* p = list;
	qlist* m = list->next;
	for (i = 1; i < 10; i++)
	{
		n = i;
		while (n-- && q->next)
		{
			q = q->next;
			p = p->next;
		}
		if (p && q)
		{
			p->next = q->next;
			q->next = m;
			list->next = q;
			q = list->next;
			p = list;
		}
	}
	printf("The data after changing is:\n");
	ldisplay(list, myprintf);
	destory_qlist(list);
}

int main()
{
	//methond1();
	methond2();
	return 0;
}