#include "qlist.h"

void myprint(qlist* node)
{
	printf(" %d ", node->data);
}

int main()
{
	qlist* head = createqlist();
	int i = 0;
	for (i = 0; i < 10; i++)
		insert_into_qlist(head, i, i);
	display(head, myprint);
	del_from_qlist(head, 5);
	display(head, myprint);
	return 0;
}