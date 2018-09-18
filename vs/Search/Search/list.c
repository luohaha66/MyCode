#include<stdio.h>
#include<malloc.h>
#include "list.h"
/*线性表的顺序存储结构*/


//线性表的创建
void* Slist_creat(int capacity)
{
	Slist* ret = NULL;
	if (capacity > 0)
	{
		ret = (void*)malloc(sizeof(Slist) + sizeof(Slistnode)*capacity);
	}
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->node = (Slistnode*)(ret + 1);
	}
	return ret;
}

//线性表的销毁
void Slist_destory(Slist* list)
{
	free(list);
}

//线性表长度获取
int Slist_length(Slist* list)
{
	int ret = -1;
	if (list != NULL)
		ret = list->length;
	return ret;
}

//线性表最大容量获取
int Slist_capacity(Slist* list)
{
	int ret = -1;
	if (list != NULL)
		ret = list->capacity;
	return ret;
}

//线性表的元素获取
int Slist_get(Slist* list, int pos)
{
	int ret=0;
	if ((list != NULL) && (pos >= 0) && (pos <= list->length))
	{
		ret = (list->node[pos]);
	}
	return ret;
}

//线性表元素的插入
int Slist_insert(Slist* list, int node, int pos)
{
	int i = 0;
	int ret = (list != NULL);
	ret = ret && (list->length + 1 <= list->capacity);
	ret = ret && (pos >= 0);
	if (ret)
	{
		if (pos >= list->length)
			pos = list->length;
		for (i = list->length; i > pos; i--)
		{
			list->node[i] = list->node[i - 1];
		}
		list->node[i] = node;
		list->length++;
	}
	return ret;
}

//线性表元素的删除
void  Slist_delete(Slist* list, int pos)
{
	int i = 0;
	if (pos >= 0 && (pos <= list->length) && (list != NULL))
	{
		for (i = pos + 1; i <= list->length; i++)
			list->node[i - 1] = list->node[i];
	}
	list->length--;
}