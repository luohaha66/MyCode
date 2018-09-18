#include "tree.h"
#include "lqueue.h"

int main()
{
	tree* root = createTree(1, 12);
	pre_order_traversal(root);
	printf("\n");
	middle_order_traversal(root);
	printf("\n");
	post_order_traversal(root);
	printf("\n");
	level_order_traversal(root);
	printf("\n");
	destory_tree(root);
	return 0;
}