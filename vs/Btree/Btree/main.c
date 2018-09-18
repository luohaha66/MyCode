#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"Btree.h"

int main(int argc, char* argv[])
{
	Btree* tree = BTree_Create();
	BTree_Insert(tree,0,'A',0,0 );
	BTree_Insert(tree, 0x00, 'B', 1, 0);
	BTree_Insert(tree, 0x01, 'C', 1, 0);
	BTree_Insert(tree, 0x00, 'D', 2, 0);
	BTree_Insert(tree, 0x02, 'E', 2, 0);
    BTree_Display(tree, 4, '*');
	printf("count is %d\n", BTree_Count(tree));
	printf("degree is %d\n",BTree_Degree(tree));
	printf("height is %d\n", BTree_Height(tree));
	pre_order_traversal(tree->root);
	printf("\n");
	middle_order_traversal(tree->root);
	printf("\n");
	post_order_traversal(tree->root);
	printf("\n");
	//level_order_traversal(tree->root);
	printf("\n");
	BTree_Destroy(tree);
	return 0;
}