#include<stdio.h>
#include<stdlib.h>

struct stack{
   int size;
   int top;
   int * arr;
};


int isEmpty(struct stack* ptr){
    if(ptr->top == -1){ //here top refers to top element in stack
        return 1;
    }
    else    {
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr , int val ){
    if(isFull(ptr)){
        printf("Stack Overflow ! Cannot push %d to stack \n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }

}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow ! Cant POP the items thus it is empty ");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    int n;
    printf("Enter size of Stack : ");
    scanf("%d",&n);
    sp->size = n;
    sp->top = -1;
    sp->arr = (int*) malloc(sp->size * sizeof(int));
    printf("Stack has been created Successfully");

    printf("\n%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    push(sp,45);
    printf("POP %d from Stack",pop(sp));
    pop(sp);
    printf("%d\n",isFull(sp));
    return 0;
}