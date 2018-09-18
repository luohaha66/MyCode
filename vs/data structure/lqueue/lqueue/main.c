#include "lqueue.h"

void myprintf(lqueue* lq)
{
	printf(" %d ", lq->data);
}

int main()
{
	point* lq = create_lqueue();
	if (!lq)
		printf("error\n");
	int i = 10;
	while (i--)
		insert_into_lqueue(lq, i);
	displaylq(lq, myprintf);
	del_from_lqueue(lq);
	del_from_lqueue(lq);
	displaylq(lq, myprintf);
	destory_lqueue(lq);
	return 0;
}