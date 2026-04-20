#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

void dijkstra(int n, int graph[MAX][MAX], int src) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 1; count <= n; count++) {
        int min = INT_MAX, u;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        if (min == INT_MAX) break;

        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, u, v, w, source;
    int graph[MAX][MAX] = {0};

    printf("Enter n and m: ");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    printf("Enter source: ");
    scanf("%d", &source);

    dijkstra(n, graph, source);

    return 0;
}