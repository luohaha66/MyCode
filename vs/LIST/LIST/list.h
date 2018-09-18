#pragma once
#ifndef _LIST_H_
#define _LIST_H_

typedef unsigned int Slistnode;
typedef struct _tag_List
{
	int capacity;
	int length;
	Slistnode* node;
}Slist;

void* Slist_creat(int capacity);

void Slist_destory(Slist* list);

int Slist_length(Slist* list);

int Slist_capacity(Slist* list);

int Slist_get(Slist* list, int pos);

int Slist_insert(Slist* list, int node, int pos);

void  Slist_delete(Slist* list, int pos);
#endif // !_LIST_H_
