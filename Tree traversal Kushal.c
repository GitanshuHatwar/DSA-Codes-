#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

typedef struct Node node;

void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
node* createNode(int value);

int main() {
    node *root, *n1, *n2, *n3, *n4, *n5, *n6;

    root = createNode(1);
    n1 = createNode(2);
    n2 = createNode(3);
    n3 = createNode(4);
    n4 = createNode(5);
    n5 = createNode(6);
    n6 = createNode(7);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preorder(node* root) {
    if (root != NULL) {
        printf("%3d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%3d", root->data);
        inorder(root->right);
    }
}

void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%3d", root->data);
    }
}

