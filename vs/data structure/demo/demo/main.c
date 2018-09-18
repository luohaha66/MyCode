#include "lstack.h"
#include "qlist.h"

void myprintf(qlist* list)
{
	printf("%d ", list->data);
}


void methond1()
{
	qlist* list = createqlist();
	qlist* q = list;
	qlist* p = list;
	qlist* m = NULL;
	qlist* n = list;
	lstack* stack = create_lstack();
	int i = 0;
	int data = 0;
	if (list == NULL || stack == NULL)
	{
		printf("Error: create failde\n");
		return -1;
	}
	for (i = 0; i < 10; i++)
		insert_into_qlist(list, i, i); /*insert some data into list*/
	printf("The data before changing is:\n");
	ldisplay(list, myprintf);
	q = q->next;
	for (i = 0; i < 10; i++)
	{
		lstack_push(stack, q); /*insert the node of list into stack*/
		q = q->next;
	}
	for (i = 0; i < 10; i++)
	{
		m = lsatck_pop(stack); /*stack pop*/
		n->next = m;
		m->next = NULL;
		n = m;

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
		q = list->next;
		p = list;
		m = list->next;
		while (n--)
		{
			q = q->next;
			p = p->next;
		}
		p->next = q->next;
		q->next = m;
		list->next = q;
	}
	printf("The data after changing is:\n");
	ldisplay(list, myprintf);
	destory_qlist(list);
}

int main()
{
	methond1();
	methond2();
	return 0;
}