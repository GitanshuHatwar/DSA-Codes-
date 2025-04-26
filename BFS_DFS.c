#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct Graph_t {
	int V;
	bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* Graph_create(int V) {
	Graph* g = malloc(sizeof(Graph));
	g->V = V;
	int i, j;
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			g->adj[i][j] = false;
		}
	}
	return g;
}

void Graph_destroy(Graph* g) {
	free(g);
}

void Graph_addEdge(Graph* g, int v, int w) {
	g->adj[v][w] = true;
}

void Graph_BFS(Graph* g, int s) {
	int i;
	bool visited[MAX_VERTICES];
	for (i = 0; i < g->V; i++) {
		visited[i] = false;
	}

	int queue[MAX_VERTICES];
	int front = 0, rear = 0;
	visited[s] = true;
	queue[rear++] = s;

	while (front != rear) {
		s = queue[front++];
		printf("%d ", s);

		for (i = 0; i < g->V; i++) {
			if (g->adj[s][i] && !visited[i]) {
				visited[i] = true;
				queue[rear++] = i;
			}
		}
	}
}

void Graph_DFS_Util(Graph* g, int v, bool visited[]) {
	int i;
	visited[v] = true;
	printf("%d ", v);

	for (i = 0; i < g->V; i++) {
		if (g->adj[v][i] && !visited[i]) {
			Graph_DFS_Util(g, i, visited);
		}
	}
}

void Graph_DFS(Graph* g, int start) {
	bool visited[MAX_VERTICES];
	int i;
	for (i = 0; i < g->V; i++) {
		visited[i] = false;
	}
	Graph_DFS_Util(g, start, visited);
}

int main() {
	Graph* g = Graph_create(4);
	Graph_addEdge(g, 0, 1);
	Graph_addEdge(g, 0, 2);
	Graph_addEdge(g, 1, 2);
	Graph_addEdge(g, 2, 0);
	Graph_addEdge(g, 2, 3);
	Graph_addEdge(g, 3, 3);

	printf("Breadth First Traversal (starting from vertex 2):\n");
	Graph_BFS(g, 2);
	printf("\n");

	printf("Depth First Traversal (starting from vertex 2):\n");
	Graph_DFS(g, 2);
	printf("\n");

	Graph_destroy(g);

	return 0;
}

