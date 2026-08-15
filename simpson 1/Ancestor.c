#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int findAncestor(struct Node *root, int x) {
    if(root == NULL)
        return 0;

    if(root->data == x)
        return 1;

    if(findAncestor(root->left, x) ||
       findAncestor(root->right, x)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

int main() {
    struct Node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);

    printf("Ancestors of 9: ");
    findAncestor(root, 9);
    printf("\n");

    return 0;
}