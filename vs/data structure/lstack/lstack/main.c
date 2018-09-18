#include "lstack.h"

void myprintf(lstack* l)
{
	printf(" %d ", l->data);
}

int main()
{
	lstack* l = create_lstack();
	int i = 10;
	while (i--)
		lstack_push(l, i);
	display(l, myprintf);
	lsatck_pop(l);
	lsatck_pop(l);
	display(l, myprintf);
	destory_lstack(l);
	return 0;
}