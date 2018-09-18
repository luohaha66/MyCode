#include "slist.h"

slist* creatslist()  /*create a slist*/
{
	slist* list = (slist*)calloc(1,sizeof(struct slist));
	if (list == NULL)
		return NULL;
	list->last = -1;
	return list;
}

void display(slist* list, void(*print)(slist* list, int i))
{
	if (list == NULL)
		return;
	int j = 0;
	int i = list->last;
	for (j; j <= i; j++)
		print(list, j);
	printf("\n");
}

int slist_is_empty(slist* list)  /*judge the slist is empty*/
{
	if (list == NULL)
		return -1;
	return  (list->last == -1);
}

int slist_is_full(slist* list)  /*judge teh slist is full*/
{
	if (list == NULL)
		return -1;
	return  (list->last == size - 1);
}

int get_slist_length(slist* list)  /*get the slist length*/ 
{
	if (list == NULL)
		return -1;
	return list->last + 1;
}

int insert_data(slist* list, int pos, data c) /*insert data into slist*/
{
	if (list == NULL)
		return -1;
	int len = get_slist_length(list);
	int i   = 0;
	if (pos < 0 || pos > len) /*whether the position is vaild*/
		return -1;
	for (i = list->last; i >= pos; i++)
	{
		list->list_data[i + 1] = list->list_data[i];
	}
	list->list_data[pos] = c;
	list->last++;
	return 0;
}

data get_data_atpos(slist* list, int i) /*get the data at pos i*/
{
	if (list == NULL)
		return -1;
	if (i < 0 || i > list->last)
		return -1;
	return list->list_data[i];
}

int del_data_pos(slist* list, int pos) /*del element from slist according to position*/
{
	if (list == NULL)
		return -1;
	if (pos < 0 || pos > list->last)
		return -1;
	if (slist_is_empty(list))
		return -1;
	int i = 0;
	for (i = pos; i <= list->last; i++)
	{
		list->list_data[i] = list->list_data[i + 1];
	}
	list->last--;
	return 0;
}

int del_data_data(slist* list, data c) /*del element from slist according to data*/
{
	if (list == NULL)
		return -1;
	if (slist_is_empty(list))
		return -1;
	int pos = find_element_data(list, c);
	if (pos == -1)
		return -1;
	del_data_pos(list, pos);
	list->last--;
	return 0;
}

int find_element_data(slist* list, data c) /*find element according to data*/
{
	if (list == NULL)
		return -1;
	if (slist_is_empty(list))
		return -1;
	int i = 0;
	int k = 0;
	for (i = 0; i < list->last; i++)
	{
		if (list->list_data[i] == c)
			return i;
	}
	return -1;
}

int find_and_replace(slist* list, data a, data c) /*find element and replace*/
{
	int i = find_element_data(list, a);
	if (i == -1)
		return -1;
	list->list_data[i] = c;
	return 0;
}

void slist_destory(slist* list)
{
	free (list);
	list = NULL;
}