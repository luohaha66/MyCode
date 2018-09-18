#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"Btree.h"
#include "Queen.h"


static int recursive_count(BtreeNode* node)
{
	int ret = 0;
	if(node != NULL)
	{
		int i = recursive_count(node->left);
		free(node->left);
		int j = recursive_count(node->right);
		free(node->right);
		ret = i + j + 1;
	}
	return ret;
}

static int recursive_height(BtreeNode* root)
{
	int ret = 0;

	if(root != NULL)
	{
		int lh = recursive_height(root->left);
		int rh = recursive_height(root->right);

		ret = ((lh > rh) ? lh : rh) + 1;
	}

	return ret;
}

static int recursive_degree(BtreeNode* root)
{
	int ret = 0;

	if(root != NULL)
	{
		if(root->left != NULL)
		{
			ret++;
		}

		if(root->right != NULL)
		{
			ret++;
		}

		if(ret == 1)
		{
			int ld = recursive_degree(root->left);
			int rd = recursive_degree(root->right);

			if(ret < ld)
			{
				ret = ld;
			}

			if(ret < rd)
			{
				ret = rd;
			}
		}
	}

	return ret;
}

static void recursive_display(BtreeNode* node,int format, int gap, char div) // O(n)
{
	int i = 0;

	if(node != NULL)
	{
		for(i = 0; i<format; i++)
		{
			printf("%c", div);
		}

		printf("%c", node->data);

		printf("\n");

		if((node->left != NULL) || (node->right != NULL))
		{
			recursive_display(node->left, format + gap, gap, div);
			recursive_display(node->right, format + gap, gap, div);
		}
	}
	else
	{
		for(i = 0; i<format; i++)
		{
			printf("%c", div);
		}
		printf("\n");
	}
}

Btree* BTree_Create()
{
	Btree* tree = (Btree*)malloc(sizeof(Btree));
	if (tree != NULL)
	{
		tree->count = 0;
		tree->root = NULL;
	}
	return tree;
}

void BTree_Destroy(Btree* tree)
{
	if (tree != NULL)
	{
		BTree_Delete(tree, 0, 0);
	}
}

int BTree_Insert(Btree* tree,BTPos pos,char c,int count, int flag)
{
	BtreeNode* node = (BtreeNode*)malloc(sizeof(BtreeNode));
	if (node != NULL)
	{
		node->left = NULL;
		node->right = NULL;
	}
	int ret = ((tree != NULL) && ((flag == BT_LEFT) || (flag = BT_RIGHT)));
	int bit = 0;
	if (ret)
	{
		BtreeNode* parent = NULL;
		BtreeNode* pitch = tree->root;
		while ((count > 0) && (pitch != NULL))
		{
			bit = pos & 1;
			pos = pos >> 1;
			parent = pitch;
			if (bit == BT_LEFT)
			{
				pitch = pitch->left;
			}
			else if (bit == BT_RIGHT)
			{
				pitch= pitch->right;
			}
			count--;
		}
		if (flag == BT_LEFT)
		{
			node->left = pitch;
			node->data = c;
		}
		else if (flag == BT_RIGHT)
		{
			node->right = pitch;
			node->data = c;
		}
		if (parent != NULL)
		{
			if (bit == BT_LEFT)
			{
				parent->left = node;
			}
			else if (bit == BT_RIGHT)
			{
				parent->right = node;
			}
		}
     else
		{
			tree->root = node;
			tree->root->data = c;
		}
		tree->count++;
	}
	return ret;
}

void BTree_Delete(Btree* tree, BTPos pos, int count)
{
	int bit = 0;
	BtreeNode* ret = NULL;
	if (tree != NULL)
	{
		BtreeNode* parent = NULL;
		BtreeNode* pitch = tree->root;
		while ((count > 0) && (pitch != NULL))
		{
			bit = pos & 1;
			pos = pos >> 1;
			parent = pitch;
			if (bit == BT_LEFT)
			{
				pitch = pitch->left;
			}
			else if (bit == BT_RIGHT)
			{
				pitch = pitch->right;
			}
			count--;
		}
		if (parent != NULL)
		{
			if (bit == BT_LEFT)
			{
				parent->left = NULL;
			}
			else if (bit == BT_RIGHT)
			{
				parent->right = NULL;
			}
		}
		else
		{
			tree->root = NULL;
		}
		ret = pitch;
		tree->count = tree->count - recursive_count(ret);
	}
	free(ret);
}

BtreeNode* BTree_Get(Btree* tree, BTPos pos, int count)
{
	BtreeNode* ret = NULL;
	int bit = 0;
	if (tree != NULL)
	{
		BtreeNode* parent = NULL;
		BtreeNode* pitch = tree->root;
		while ((count > 0) && (pitch != NULL))
		{
			bit = pos & 1;
			pos = pos >> 1;
			parent = pitch;
			if (bit == BT_LEFT)
			{
				pitch = pitch->left;
			}
			else if (bit == BT_RIGHT)
			{
				pitch = pitch->right;
			}
			count--;
		}
		ret = pitch;
	}
	return ret;
}

BtreeNode* BTree_Root(Btree* tree)
{
	BtreeNode* ret=NULL;
	if (tree != NULL)
	{
		ret = tree->root;
	}
	return ret;
}

int BTree_Height(Btree* tree)
{
	int ret = 0;
	if (tree != NULL)
	{
		ret = recursive_height(tree->root);
	}
	return ret;
}

int BTree_Count(Btree* tree)
{
	int ret = 0;
	if (tree != NULL)
	{
		ret = tree->count;
	}
	return ret;
}

int BTree_Degree(Btree* tree)
{
	int ret = 0;
	if (tree != NULL)
	{
		ret = recursive_degree(tree->root);
	}
	return ret;
}

void BTree_Display(Btree* tree, int gap, char div)
{
	if (tree != NULL)
	{
		recursive_display(tree->root, 0, gap, div);
	}
}

void pre_order_traversal(BtreeNode* root)
{
	if (root != NULL)
	{
		printf("%c, ", root->data);

		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

void middle_order_traversal(BtreeNode* root)
{
	if (root != NULL)
	{
		middle_order_traversal(root->left);


		printf("%c, ", root->data);

		middle_order_traversal(root->right);
	}
}

void post_order_traversal(BtreeNode* root)
{
	if (root != NULL)
	{
		post_order_traversal(root->left);

		post_order_traversal(root->right);

		printf("%c, ", root->data);
	}
}

void level_order_traversal(BtreeNode* root)
{
	if (root != NULL)
	{
		Queen* queen = Queen_creat();

		if (queen != NULL)
		{
			Queen_insert(queen, root);
			while (Queen_length(queen) > 0)
			{
			    BtreeNode* node = Queen_del(queen);

				printf("%c, ", node->data);
				Queen_insert(queen, node->left);
				Queen_insert(queen, node->right);
			}
		}

		Queen_destory(queen);
	}
}