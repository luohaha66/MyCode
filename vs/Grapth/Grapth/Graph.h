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

/* ������������n�������ͼ */
Graph* Graph_Create(char** GraphVertex,int n);

/* ����graph��ָ���ͼ */
void Graph_Destroy(Graph* graph);

/* ��graph��ָͼ�ı߼������ */
void Graph_Clear(Graph* graph);

/* ��graph��ָͼ�е�v1��v2֮����ϱߣ��ұߵ�ȨΪw */
int Graph_AddEdge(Graph* graph, int v1, int v2, int w);

/* ��graph��ָͼ��v1��v2֮��ı�ɾ��������Ȩֵ */
int Graph_RemoveEdge(Graph* graph, int v1, int v2);

/* ��graph��ָͼ��v1��v2֮��ıߵ�Ȩֵ���� */
int Graph_GetEdge(Graph* graph, int v1, int v2);

/* ��graph��ָͼ��v����Ķ��� */
int Graph_TD(Graph* graph, int v);

/* ��graph��ָͼ�еĶ��������� */
int Graph_VertexCount(Graph* graph);

/* ��graph��ָͼ�еı������� */
int Graph_EdgeCount(Graph* graph);

void Graph_Display(Graph* graph);

void Graph_BFS(Graph* graph, int v);

void Graph_DFS(Graph* graph, int v);

void Prim(int sv);

void Floyd();

#endif // !_GRAPH_H_
