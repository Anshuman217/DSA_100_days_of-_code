#include <stdio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node nodes[100];
struct Node* ptrs[100];

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    printf("Enter total number of numbers: ");
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) {
            ptrs[i] = NULL;
        } else {
            nodes[i].data = arr[i];
            nodes[i].left = NULL;
            nodes[i].right = NULL;
            ptrs[i] = &nodes[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if(ptrs[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n)
                ptrs[i]->left = ptrs[l];
            if(r < n)
                ptrs[i]->right = ptrs[r];
        }
    }

    inorder(ptrs[0]);

    return 0;
}