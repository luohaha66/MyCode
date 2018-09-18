#include "tree.h"
#include "lqueue.h"

tree* createTree(int i, int n) /*i is the code of the node, n is the numbers of the node*/
{
	tree* root = (tree*)calloc(1, sizeof(tree));
	if (root == NULL)
		return NULL;
	root->data = i;
	if (2 * i <= n)
		root->lchild = createTree(2 * i, n);
	else
		root->lchild = NULL;
	if (2 * i + 1 <= n)
		root->rchild = createTree(2 * i + 1, n);
	else
		root->rchild = NULL;
	return root;
}

void pre_order_traversal(tree* root)
{
	if (root == NULL)
		return;
	printf(" %d ", root->data);
	pre_order_traversal(root->lchild);
	pre_order_traversal(root->rchild);
}

void middle_order_traversal(tree* root)
{
	if (root == NULL)
		return;
	middle_order_traversal(root->lchild);
	printf(" %d ", root->data);
	middle_order_traversal(root->rchild);
}

void post_order_traversal(tree* root)
{
	if (root == NULL)
		return;
	post_order_traversal(root->lchild);
	post_order_traversal(root->rchild);
	printf(" %d ", root->data);
}

void level_order_traversal(tree* root)
{
	if (root == NULL)
		return;
	lqueue* lq = create_lqueue();
	tree* q = NULL;
	if (lq == NULL)
		return;
	insert_into_lqueue(lq, root);
	while (!lqueue_is_empty(lq))
	{
		q = del_from_lqueue(lq);
		printf(" %d ", q->data);
		if (q->lchild)
			insert_into_lqueue(lq, q->lchild);
		if (q->rchild)
			insert_into_lqueue(lq, q->rchild);
	}
	destory_lqueue(lq);
}

void destory_tree(tree* root)
{
	if (root == NULL)
		return;
	lqueue* lq = create_lqueue();
	tree* q = NULL;
	if (lq == NULL)
		return;
	insert_into_lqueue(lq, root);
	while (!lqueue_is_empty(lq))
	{
		q = del_from_lqueue(lq);
		if (q->lchild)
			insert_into_lqueue(lq, q->lchild);
		if (q->rchild)
			insert_into_lqueue(lq, q->rchild);
		free(q);
		q = NULL;
	}
	destory_lqueue(lq);
}