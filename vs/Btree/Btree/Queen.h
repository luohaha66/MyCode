#pragma once
#ifndef _QUEEN_H_
#define _QUEEN_H_

typedef struct QNODE
{
	int data;
	struct QNODE* prior;
}Qnode;

typedef struct QUEEN
{
	int length;
	Qnode* front;
	Qnode* rear;
}Queen;

Queen* Queen_creat();

void Queen_insert(Queen* queen, int n);

int Queen_del(Queen* queen);

int Queen_length(Queen* queen);

void Queen_destory(Queen* queen);

void Queen_clear(Queen* queen);

#endif // !_QUEEN_H_
