#pragma once
#ifndef _GRAPH_H_
#define _GRAPH_H_
#define VUM 9
#define VNUM 5
#define MV 65536

typedef struct Graph
{
	int count;
	char** GraphVertex;
	int** GraphEdge;
}Graph;

/* 创建并返回有n个顶点的图 */
Graph* Graph_Create(char** GraphVertex,int n);

/* 销毁graph所指向的图 */
void Graph_Destroy(Graph* graph);

/* 将graph所指图的边集合清空 */
void Graph_Clear(Graph* graph);

/* 在graph所指图中的v1和v2之间加上边，且边的权为w */
int Graph_AddEdge(Graph* graph, int v1, int v2, int w);

/* 将graph所指图中v1和v2之间的边删除，返回权值 */
int Graph_RemoveEdge(Graph* graph, int v1, int v2);

/* 将graph所指图中v1和v2之间的边的权值返回 */
int Graph_GetEdge(Graph* graph, int v1, int v2);

/* 将graph所指图中v顶点的度数 */
int Graph_TD(Graph* graph, int v);

/* 将graph所指图中的顶点数返回 */
int Graph_VertexCount(Graph* graph);

/* 将graph所指图中的边数返回 */
int Graph_EdgeCount(Graph* graph);

void Graph_Display(Graph* graph);

void Graph_BFS(Graph* graph, int v);

void Graph_DFS(Graph* graph, int v);

void Prim(int sv);

void Floyd();

#endif // !_GRAPH_H_
