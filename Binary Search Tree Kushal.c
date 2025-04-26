#include <stdio.h>
#include <stdlib.h>


struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

typedef struct Node node;

node* insert(node* root, int value);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);

int main() {
    node* root = NULL;


    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

  
    printf("Preorder Traversal of BST: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal of BST: ");
    postorder(root);
    printf("\n");

    return 0;
}


node* insert(node* root, int value) {
    if (root == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
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

