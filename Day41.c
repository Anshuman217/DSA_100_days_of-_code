#include <stdio.h>

int main() {
    int n, i;

    scanf("%d", &n);

    int queue[n];
    int stack[n];
    int top = -1;

    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    for(i = 0; i < n; i++) {
        top++;
        stack[top] = queue[i];
    }

    for(i = 0; i < n; i++) {
        queue[i] = stack[top];
        top--;
    }

    for(i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}