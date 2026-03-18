#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 0;

    while (front < rear) {

        int count = rear - front;

        result[level] = (int*)malloc(count * sizeof(int));
        (*returnColumnSizes)[level] = count;

        for (int i = 0; i < count; i++) {
            struct TreeNode* curr = queue[front++];

            result[level][i] = curr->val;

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        level++;
    }

    *returnSize = level;
    return result;
}

void printResult(int** result, int returnSize, int* returnColumnSizes) {
    printf("[\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  [");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
    }
    printf("]\n");
}

int main() {


    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int returnSize;
    int* returnColumnSizes;

    int** result = levelOrder(root, &returnSize, &returnColumnSizes);

    printResult(result, returnSize, returnColumnSizes);

    return 0;
}