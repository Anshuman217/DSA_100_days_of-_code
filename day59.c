#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* constructTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIdx) {
    if (inStart > inEnd) {
        return NULL;
    }

    int currentRootValue = postorder[*postIdx];
    struct Node* root = createNode(currentRootValue);
    (*postIdx)--;

    if (inStart == inEnd) {
        return root;
    }

    int splitPoint = findIndex(inorder, inStart, inEnd, currentRootValue);

    root->right = constructTree(inorder, postorder, splitPoint + 1, inEnd, postIdx);
    root->left = constructTree(inorder, postorder, inStart, splitPoint - 1, postIdx);

    return root;
}

void showPreorder(struct Node* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);
    showPreorder(root->left);
    showPreorder(root->right);
}

int main() {
    int n;

    printf("Enter the number of nodes in the tree: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int inorder[n], postorder[n];

    printf("Enter the inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter the postorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int currentPostIdx = n - 1;
    struct Node* root = constructTree(inorder, postorder, 0, n - 1, &currentPostIdx);

    printf("\nResulting Preorder traversal: ");
    showPreorder(root);
    printf("\n");

    return 0;
}