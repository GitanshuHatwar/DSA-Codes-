#include<stdio.h>
#include<stdlib.h>

struct Circular_Queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct Circular_Queue *q){
    if((q->r+1)%q->size == q->f ){
        return 1;
    }
    return 0;
}

int isEmpty(struct Circular_Queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enCircular_Queue(struct Circular_Queue *q,int val){
    if(isFull(q)){
         //printf("This Circular_Queue is Full");
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r]=val; 
        printf("Enqueued Element : %d\n",val);
    }
}

int deCircular_Queue(struct Circular_Queue *q){
    if(isEmpty(q)){
         printf("This Circular_Queue is Empty\n");
        return 0;
    }
    else{
       q->f = (q->f +1)%q->size;
       return q-> arr[q->f];
    }
}


int main(){
    struct Circular_Queue q;
    q.size=3;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    enCircular_Queue(&q,12);
    enCircular_Queue(&q,23);

    printf("DeCircular_Queue Element %d \n",deCircular_Queue(&q));
    printf("DeCircular_Queue Element %d \n",deCircular_Queue(&q));

    enCircular_Queue(&q,34);
    printf("DeCircular_Queue Element %d \n",deCircular_Queue(&q));

    if(isEmpty(&q)){
        printf("Circular_Queue is Empty\n");
    }

    if(isFull(&q)){
        printf("Circular_Queue is Full\n");
    }


    return 0;
}
