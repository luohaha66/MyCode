#include<stdio.h>
#include "recursion.h"
int feibo(int n)
{
	if (n > 1)
	{
		return feibo(n - 2) + feibo(n - 1);
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (n == 0)
	{
		return 0;
	}
	return 0;
}

int strlength(const char* s)
{
	if (s == NULL)
	{
		return - 1;
	}
	else if (*s == '\0')
	{
		return 0;
	}
	else 
	{
		return strlength(s + 1) + 1;
	}
	return 0;
}

void init_board()
{
	int i = 0;
	int j = 1;
	for (i = 0; i < N + 2; i++)
	{
		board[0][i] = '#';
		board[N + 1][i] = '#';
		board[i][0] = '#';
		board[i][N + 1] = '#';
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
			board[i][j] = ' ';
	}
}

void display()
{
	int i = 0;
	int j = 1;
	for (i = 0; i < N + 2; i++)
	{
		for (j = 0; j < N + 2; j++)
		{
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int check(int i, int j)
{
	int ret = 1;
	int p = 0;

	for (p = 0; p<3; p++)
	{
		int ni = i;
		int nj = j;

		while (ret && (board[ni][nj] != '#'))
		{
			ni = ni + po[p].ios;
			nj = nj + po[p].jos;

			ret = ret && (board[ni][nj] != '*');
		}
	}

	return ret;
}

void find(int i)
{
	int j = 0;

	if (i > N)
	{
		count++;

		printf("Solution: %d\n", count);

		display();

		getchar();
	}
	else
	{
		for (j = 1; j <= N; j++)
		{
			if (check(i, j))
			{
				board[i][j] = '*';

				find(i + 1);

				board[i][j] = ' ';
			}
		}
	}
}