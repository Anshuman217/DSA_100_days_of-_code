#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node** adjList = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adjList[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}