#include<stdio.h>
#include<malloc.h>
#include "list.h"
/*���Ա��˳��洢�ṹ*/


//���Ա�Ĵ���
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

//���Ա������
void Slist_destory(Slist* list)
{
	free(list);
}

//���Ա��Ȼ�ȡ
int Slist_length(Slist* list)
{
	int ret = -1;
	if (list != NULL)
		ret = list->length;
	return ret;
}

//���Ա����������ȡ
int Slist_capacity(Slist* list)
{
	int ret = -1;
	if (list != NULL)
		ret = list->capacity;
	return ret;
}

//���Ա��Ԫ�ػ�ȡ
int Slist_get(Slist* list, int pos)
{
	int ret=0;
	if ((list != NULL) && (pos >= 0) && (pos <= list->length))
	{
		ret = (list->node[pos]);
	}
	return ret;
}

//���Ա�Ԫ�صĲ���
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

//���Ա�Ԫ�ص�ɾ��
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