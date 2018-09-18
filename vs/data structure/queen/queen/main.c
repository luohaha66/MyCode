#include "queue.h"

void myprintf(queue* q, int i)
{
	printf(" %d ", q->data[i]);
}

int main()
{
	queue* q = create_queue();
	int i = 10;
	while (i--)
		insert_into_queue(q, i);
	qdisplay(q, myprintf);
	del_from_queue(q);
	del_from_queue(q);
	qdisplay(q, myprintf);
	destory_queue(q);
	return 0;
}