#pragma once
#ifndef _RECURSION_H_
#define _RECURSION_H_
#define N 8

typedef struct POS
{
	int ios;
	int jos;
}pos;

static char board[N + 2][N + 2];
static pos po[] = { {-1,-1},{-1,0},{-1,1} };
static int count = 0;

int feibo(int n);

int strlength(const char* s);

void init_board();

void display();

int check(int i, int j);

void find(int i);

#endif // !_RECURSION_H_
