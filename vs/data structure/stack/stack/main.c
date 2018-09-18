#include "srtack.h"

void myprintf(stack* s, int i)
{
	printf(" %d ", s->data[i]);
}

int main()
{
	stack* s = create_stack();
	int i = 10;
	while (i--)
		stack_push(s, i);
	display(s, myprintf);
	stack_pop(s);
	stack_pop(s);
	display(s, myprintf);
	return 0;
}