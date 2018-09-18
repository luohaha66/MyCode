#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <cstdio>

using namespace std;

template <class T>
class list {
public:
	list();
	~list();
	void insert(int pos, T d);
	T del(int pos);
	void change_bypos(int pos, T d);
	T query_by_pos(int pos);
	void display();
private:
	typedef struct node {
		node* next;
		T data;
	}qlist;
	int length;
	qlist* head;
};

#endif // !_LIST_H_
