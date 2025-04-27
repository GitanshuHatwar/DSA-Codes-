#include<stdio.h>

#define MAX_VERTICES 50

void createAdjacencyMatrix(int adj[MAX_VERTICES][MAX_VERTICES], int vertices, int edges) {
    int i, startVertex, endVertex;
    for (i = 0; i < edges; i++) {
        printf("Enter edge %d (start and end vertex): ", i + 1);
        scanf("%d %d", &startVertex, &endVertex);
        adj[startVertex][endVertex] = 1;
        adj[endVertex][startVertex] = 1;
    }
}

void displayAdjacencyMatrix(int adj[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    createAdjacencyMatrix(adj, vertices, edges);
    displayAdjacencyMatrix(adj, vertices);

    return 0;
}

