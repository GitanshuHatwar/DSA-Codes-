#include <stdio.h>
#include <stdlib.h>


struct Node {
    struct Node* left;
    char data;
    struct Node* right;
};

typedef struct Node node;


void inorder(node* root);
void preorder(node* root);
void postorder(node* root);

int main() {
    node *a, *b, *c, *d, *e;

    a = (node*)malloc(sizeof(node));
    b = (node*)malloc(sizeof(node));
    c = (node*)malloc(sizeof(node));
    d = (node*)malloc(sizeof(node));
    e = (node*)malloc(sizeof(node));

  
    a->data = 'A';
    b->data = 'B';
    c->data = 'C';
    d->data = 'D';
    e->data = 'E';

  
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = c->right = NULL;
    d->left = d->right = NULL;
    e->left = e->right = NULL;

   
    printf("Preorder Traversal of Binary Tree: ");
    preorder(a);
    printf("\n");

    printf("Inorder Traversal of Binary Tree: ");
    inorder(a);
    printf("\n");

    printf("Postorder Traversal of Binary Tree: ");
    postorder(a);
    printf("\n");

    return 0;
}


void preorder(node* root) {
    if (root != NULL) {
        printf("%3c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%3c", root->data);
        inorder(root->right);
    }
}


void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%3c", root->data);
    }
}



