#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;

};

struct node * search(struct node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }

    else if (key<root->data){
        return search(root->left, key);
    }

    else{
        return search(root->right, key);
    }
}

struct node* createNode(int data){
    struct node *n;
    n = (struct node *) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;

}



int main(){
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(3);


    p->left = p1;
    p->right = p2;

    struct node * n = search(p,3);
    if(n!=NULL){
    printf("\nFound : %d\n",n->data);
    }

    else{
        printf("Element Not found !\n");
    }
    return 0;
}