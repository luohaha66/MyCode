#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int data_tr;
typedef struct tree {
	data_tr data;
	struct tree* lchild;
	struct tree* rchild;
}tree;

tree* createTree(int i, int n);
void pre_order_traversal(tree* root);
void middle_order_traversal(tree* root);
void post_order_traversal(tree* root);
void level_order_traversal(tree* root);
void destory_tree(tree* root);

#endif // !_TREE_H_
