#include "lstack.h"

void sdisplay(lstack* l, void(*print)(lstack*))
{
	if (l == NULL)
		return;
	lstack* q = l->next;
	while (q)
	{
		print(q);
		q = q->next;
	}
	printf("\n");
}

lstack* create_lstack() /*create a link list*/
{
	lstack *l = (lstack*)calloc(1, sizeof(struct stack));
	if (l == NULL)
		return NULL;
	l->data = NULL;
	l->next = NULL;
	return l;
}

int lstack_is_empty(lstack* l)
{
	if (l == NULL)
		return -1;
	return ((l->next == NULL) ? 1 : 0);
}

int get_ele_number(lstack* l)
{
	if (l == NULL)
		return -1;
	lstack* q = l->next;
	int i = 0;
	while (q)
	{
		i++;
		q = q->next;
	}
	return i;
}

int lstack_push(lstack* l, data_st data)
{
	if (l == NULL)
		return -1;
	lstack* q = (lstack*)calloc(1, sizeof(struct stack));
	if (q == NULL)
		return -1;
	q->data = data;
	q->next = NULL;
	q->next = l->next;
	l->next = q;
	return 0;
}

data_st lsatck_pop(lstack* l)
{
	if (l == NULL)
		return -1;
	data_st c = NULL;
	lstack* q = l->next;
	c = q->data;
	l->next = q->next;
	free(q);
	return c;
}

void clear_lstack(lstack* l)
{
	if (l == NULL)
		return;
	lstack* p = l;
	lstack* q = l->next;
	while (q)
	{
		p = q->next;
		free(q);
		q = p;
	}
}

void destory_lstack(lstack* l)
{
	if (l == NULL)
		return;
	clear_lstack(l);
	free(l);
	l = NULL;
}
