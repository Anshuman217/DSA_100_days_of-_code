#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int **adj, int *size, bool *visited, bool *recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, size, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycle(int V, int **adj, int *size) {
    bool *visited = (bool *)calloc(V, sizeof(bool));
    bool *recStack = (bool *)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, size, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int **adj = (int **)malloc(V * sizeof(int *));
    int *size = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
        adj[i] = (int *)malloc(V * sizeof(int));

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
    }

    if (hasCycle(V, adj, size))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}