#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;

};

void LinkedListTraverser(struct Node* ptr){
    while(ptr!=NULL){
    printf("Element :  %d\n",ptr->data);
    ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Deletion from Link List 
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;

    for (int i = 0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}


struct Node * deleteAtValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}


int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node * ) malloc(sizeof(struct Node));
    second = (struct Node * ) malloc(sizeof(struct Node));
    third = (struct Node * ) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 14;
    second->next = third;

    third->data = 21;
    third->next = NULL;

    printf("Before Deletion : \n");
    LinkedListTraverser(head);

    // head = deleteFirst(head);
    //head = deleteAtIndex(head, 1);
    //head = deleteAtEnd(head);
    head = deleteAtValue(head, 14);
    printf("After Deletion : \n");
    LinkedListTraverser(head);
    
    return 0;
}