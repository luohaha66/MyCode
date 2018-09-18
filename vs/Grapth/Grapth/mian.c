#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	
	char* v[] = { "A" };
	Graph* graph = Graph_Create(v, 1);

	Graph_AddEdge(graph, 0, 1, 1);
	Graph_AddEdge(graph, 0, 2, 1);
	Graph_AddEdge(graph, 0, 3, 1);
	Graph_AddEdge(graph, 1, 5, 1);
	Graph_AddEdge(graph, 1, 4, 1);
	Graph_AddEdge(graph, 2, 1, 1);
	Graph_AddEdge(graph, 3, 4, 1);
	Graph_AddEdge(graph, 4, 2, 1);
	Graph_Display(graph);
	Graph_Destroy(graph);
	return 0;
}
