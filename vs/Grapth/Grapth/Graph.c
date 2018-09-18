#include <malloc.h>
#include<stdio.h>
#include "Graph.h"
#include "Queen.h"


static void recursive_dfs(Graph* graph, int v, int* visited)
{
	int i = 0;

	printf("%s", graph->GraphVertex[v]);

	visited[v] = 1;

	printf(", ");

	for (i = 0; i<graph->count; i++)
	{
		if ((graph->GraphEdge[v][i] != 0) && !visited[i])
		{
			recursive_dfs(graph, i, visited);
		}
	}
}

static void bfs(Graph* graph, int v, int* visited)
{
	Queen* queen = Queen_creat();

	if (queen != NULL)
	{
		Queen_insert(queen, (char)(graph->GraphVertex[v]+v));

		visited[v] = 1;

		while (Queen_length(queen) > 0)
		{
			int i = 0;

			v = Queen_del(queen) - (char)(graph->GraphVertex[v]);

			printf("%s",graph->GraphVertex[v]);

			printf(", ");

			for (i = 0; i<graph->count; i++)
			{
				if ((graph->GraphEdge[v][i] != 0) && !visited[i])
				{
					Queen_insert(queen, (char)(graph->GraphVertex[v]+i));

					visited[i] = 1;
				}
			}
		}
	}

	Queen_destory(queen);
}

Graph* Graph_Create(char** GraphVertex,int n)
{
	Graph* ret = NULL;
	if ((GraphVertex != NULL) && n > 0)
	{
		ret = (Graph*)malloc(sizeof(Graph));
	}
	if (ret != NULL)
	{
		int* p = NULL;
		ret->count = n;
		ret->GraphVertex = (char**)malloc(sizeof(char*)*n);
		ret->GraphEdge = (int**)malloc(sizeof(int*)*n);
		p = (int*)calloc(n*n, sizeof(int));
		if ((ret->GraphEdge != NULL) && (ret->GraphVertex != NULL) && (p != NULL))
		{
			int i = 0;
			for (i = 0; i < n; i++)
			{
				ret->GraphVertex[i]= GraphVertex[i];
				ret->GraphEdge[i] = p + i*n;
			}
		}
		else
		{
			free(p);
			free(ret->GraphEdge);
			free(ret->GraphVertex);
			free(ret);
			ret = NULL;
		}
	}
	return ret;
}

void Graph_Destroy(Graph* graph)
{
	if (graph != NULL)
	{
		free(graph->GraphVertex);
		free(graph->GraphEdge[0]);
		free(graph->GraphEdge);
		free(graph);
	}
}

void Graph_Clear(Graph* graph)
{
	int i = 0;
	int j = 0;
	if (graph != NULL)
	{
		for (i = 0; i < graph->count; i++)
		{
			for (j = 0; j < graph->count; j++)
			{
				graph->GraphEdge[i][j] = 0;
			}
		}
	}
}

int Graph_AddEdge(Graph* graph, int v1, int v2, int w)
{
	int ret = (graph != NULL);
	ret = ret && (v1 >= 0) && (v1 < graph->count);
	ret = ret && (v2 >= 0) && (v2 < graph->count);
	if (ret)
	{
		graph->GraphEdge[v1][v2] = w;
	}
	return ret;
}

int Graph_RemoveEdge(Graph* graph, int v1, int v2)
{
	int ret = Graph_GetEdge(graph, v1, v2);
	if (ret != 0);
	{
		graph->GraphEdge[v1][v2] = 0;
	}
	return ret;
}

int Graph_GetEdge(Graph* graph, int v1, int v2)
{
	int valaue=0;
	int ret = (graph != NULL);
	ret = ret && (v1 >= 0) && (v1 < graph->count);
	ret = ret && (v2 >= 0) && (v2 < graph->count);
	if (ret)
	{
		valaue = graph->GraphEdge[v1][v2];
	}
	return valaue;
}

int Graph_TD(Graph* graph, int v)
{ 
	int ret = 0;
	int condition = (graph != NULL);
	condition = condition && (v>=0) && (v<graph->count);
	if (condition)
	{
		int i = 0;
		for (i = 0; i < graph->count; i++)
		{
			if (graph->GraphEdge[v][i] != 0)
			{
				ret++;
			}
			if (graph->GraphEdge[i][v] != 0)
			{
				ret++;
			}
		}
	}
	return ret;
}

int Graph_VertexCount(Graph* graph)
{
	int ret = 0;
	if (graph != NULL)
	{
		ret = graph->count;
	}
	return ret;
}

int Graph_EdgeCount(Graph* graph)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	for (i = 0; i < graph->count; i++)
	{
		for (j = 0; j < graph->count; j++)
		{
			if (graph->GraphEdge[i][j] != 0)
			{
				ret++;
			}
		}
	}
	return ret;
}

void Graph_Display(Graph* graph)
{
	if ((graph != NULL))
	{
		int i = 0;
		int j = 0;

		for (i = 0; i<graph->count; i++)
		{
			printf("%d:", i);
			printf("%s",graph->GraphVertex[i]);
			printf(" ");
		}

		printf("\n");

		for (i = 0; i<graph->count; i++)
		{
			for (j = 0; j<graph->count; j++)
			{
				if (graph->GraphEdge[i][j] != 0)
				{
					printf("<");
					printf("%s",graph->GraphVertex[i]);
					printf(", ");
					printf("%s",graph->GraphVertex[j]);
					printf(", %d", graph->GraphEdge[i][j]);
					printf(">");
					printf(" ");
					printf("\n");
				}
			}
		}

		printf("\n");
	}
}
void Graph_BFS(Graph* graph, int v)
{
	int* visited = NULL;
	int condition = (graph != NULL);

	condition = condition && (0 <= v) && (v < graph->count);
	condition = condition && ((visited = (int*)calloc(graph->count, sizeof(int))) != NULL);

	if (condition)
	{
		int i = 0;

		recursive_dfs(graph, v, visited);

		for (i = 0; i<graph->count; i++)
		{
			if (!visited[i])
			{
				recursive_dfs(graph, i, visited);
			}
		}

		printf("\n");
	}

	free(visited);
}

void Graph_DFS(Graph* graph, int v)
{
	int* visited = NULL;
	int condition = (graph != NULL);

	condition = condition && (0 <= v) && (v < graph->count);
	condition = condition && ((visited = (int*)calloc(graph->count, sizeof(int))) != NULL);

	if (condition)
	{
		int i = 0;

		bfs(graph, v, visited);

		for (i = 0; i<graph->count; i++)
		{
			if (!visited[i])
			{
				bfs(graph, i, visited);
			}
		}

		printf("\n");
	}

	free(visited);
}

//最小联通网
int P[VUM];
int Cost[VUM];
int Mark[VUM];
int Mat[VUM][VUM] =
{
	{ 0, 10, MV, MV, MV, 11, MV, MV, MV },
	{ 10, 0, 18, MV, MV, MV, 16, MV, 12 },
	{ MV, 18, 0, 22, MV, MV, MV, MV, 8 },
	{ MV, MV, 22, 0, 20, MV, MV, 16, 21 },
	{ MV, MV, MV, 20, 0, 26, MV, 7, MV },
	{ 11, MV, MV, MV, 26, 0, 17, MV, MV },
	{ MV, 16, MV, MV, MV, 17, 0, 19, MV },
	{ MV, MV, MV, 16, 7, MV, 19, 0, MV },
	{ MV, 12, 8, 21, MV, MV, MV, MV, 0 },
};
void Prim(int sv) // O(n*n)
{
	int i = 0;
	int j = 0;

	if ((0 <= sv) && (sv < VUM))
	{
		for (i = 0; i<VUM; i++)
		{
			Cost[i] = Mat[sv][i];
			P[i] = sv;
			Mark[i] = 0;
		}

		Mark[sv] = 1;

		for (i = 0; i<VUM; i++)
		{
			int min = MV;
			int index = -1;

			for (j = 0; j<VUM; j++)
			{
				if (!Mark[j] && (Cost[j] < min))
				{
					min = Cost[j];
					index = j;
				}
			}

			if (index > -1)
			{
				Mark[index] = 1;

				printf("(%d, %d, %d)\n", P[index], index, Cost[index]);
			}

			for (j = 0; j<VUM; j++)
			{
				if (!Mark[j] && (Mat[index][j] < Cost[j]))
				{
					Cost[j] = Mat[index][j];
					P[j] = index;
				}
			}
		}
	}
}

//最短路径：

int Pp[VNUM][VNUM];
int A[VNUM][VNUM];
int Matrix[VNUM][VNUM] =
{
	{ 0, 10, MV, 30, 100 },
	{ MV, 0, 50, MV, MV },
	{ MV, MV, 0, MV, 10 },
	{ MV, MV, 20, 0, 60 },
	{ MV, MV, MV, MV, 0 },
};

void Floyd() // O(n*n*n)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i<VNUM; i++)
	{
		for (j = 0; j<VNUM; j++)
		{
			A[i][j] = Matrix[i][j];
			Pp[i][j] = j;
		}
	}

	for (i = 0; i<VNUM; i++)
	{
		for (j = 0; j<VNUM; j++)
		{
			for (k = 0; k<VNUM; k++)
			{
				if ((A[j][i] + A[i][k]) < A[j][k])
				{
					A[j][k] = A[j][i] + A[i][k];
					Pp[j][k] = Pp[j][i];
				}
			}
		}
	}

	for (i = 0; i<VNUM; i++)
	{
		for (j = 0; j<VNUM; j++)
		{
			int p = -1;

			printf("%d -> %d: %d\n", i, j, A[i][j]);

			printf("%d", i);

			p = i;

			do
			{
				p = Pp[p][j];

				printf(" -> %d", p);
			} while (p != j);

			printf("\n");
		}
	}
}