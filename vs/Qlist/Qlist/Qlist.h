#ifndef _QLIST_H_
#define _QLIST_H_

typedef struct Qlist
{
	int length;
	int data;
	struct Qlist *next;
	struct Qlist *prior;
	struct Qlist *slider;
}Qlist;


Qlist* Qlist_creat();

void Qlist_destory(Qlist* list);

void Qlist_clear(Qlist* list);

int Qlist_length(Qlist* list);

int Qlist_insert(Qlist* list, int node, int pos);

Qlist* Qlist_get(Qlist* list,int pos);

void Qlist_delete(Qlist* list, int pos);

void Qlist_delete_slider(Qlist* list, int j);

Qlist* Qlist_reset_slider(Qlist* list);

Qlist* QList_get_slider(Qlist* list);

Qlist* QList_moveup_slider(Qlist* list);

Qlist* QList_movedown_slider(Qlist* list);
#endif // !_QLIST_H_
