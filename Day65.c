//Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdlib.h>

int hasCycle(int v, int parent, int visited[], int **adj, int V) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (hasCycle(i, v, visited, adj, V)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)calloc(V, sizeof(int));
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int *visited = (int *)calloc(V, sizeof(int));
    int cycle = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1, visited, adj, V)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle) printf("YES\n");
    else printf("NO\n");

    for (int i = 0; i < V; i++) free(adj[i]);
    free(adj);
    free(visited);

    return 0;
}