//Perform DFS starting from a given source vertex using recursion
#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int **adj, int *visited) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    int *visited = (int *)calloc(n, sizeof(int));

    printf("DFS traversal: ");
    dfs(s, n, adj, visited);

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);

    return 0;
}
