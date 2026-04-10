#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 1000000000

typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX * MAX];
int size = 0;

void swap(int a, int b) {
    HeapNode t = heap[a];
    heap[a] = heap[b];
    heap[b] = t;
}

void push(int node, int dist) {
    size++;
    heap[size].node = node;
    heap[size].dist = dist;
    int i = size;
    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        swap(i, i / 2);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[size--];
    int i = 1;
    while (1) {
        int l = 2 * i;
        int r = 2 * i + 1;
        int s = i;
        if (l <= size && heap[l].dist < heap[s].dist) s = l;
        if (r <= size && heap[r].dist < heap[s].dist) s = r;
        if (s != i) {
            swap(i, s);
            i = s;
        } else break;
    }
    return root;
}

int main() {
    int n, m;
    int adj[MAX][MAX];
    int dist[MAX];
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = INF;

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        HeapNode cur = pop();
        int u = cur.node;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                push(v, dist[v]);
            }
        }
    }

    printf("Shortest distances from source:\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}