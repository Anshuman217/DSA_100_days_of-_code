#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = 0, rear = -1;
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue → stack
    for(int i = 0; i < n; i++)
        push(dequeue());

    // Move stack → queue
    for(int i = 0; i < n; i++)
        enqueue(pop());

    // Print reversed queue
    printf("Reversed queue: ");
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}