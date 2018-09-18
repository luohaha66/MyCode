#pragma once
#ifndef _BTREE_H_
#define _BTREE_H_

#define BT_LEFT 0
#define BT_RIGHT 1

typedef unsigned long long BTPos;

typedef struct BtreeNode
{
	char data;
	struct BtreeNode* left;
	struct BtreeNode* right;
}BtreeNode;

typedef struct Btree
{
	BtreeNode* root;
	int count;
}Btree;

static int recursive_count(BtreeNode* node);

static int recursive_height(BtreeNode* root);

static int recursive_degree(BtreeNode* root);

static void recursive_display(BtreeNode* node, int format, int gap, char div);

Btree* BTree_Create();

void BTree_Destroy(Btree* tree);

int BTree_Insert(Btree* tree, BTPos pos, char c,int count, int flag);

void BTree_Delete(Btree* tree, BTPos pos, int count);

BtreeNode* BTree_Get(Btree* tree, BTPos pos, int count);

BtreeNode* BTree_Root(Btree* tree);

int BTree_Height(Btree* tree);

int BTree_Count(Btree* tree);

int BTree_Degree(Btree* tree);

void BTree_Display(Btree* tree, int gap, char div);

void pre_order_traversal(BtreeNode* root);

void middle_order_traversal(BtreeNode* root);

void post_order_traversal(BtreeNode* root);

void level_order_traversal(BtreeNode* root);

#endif

