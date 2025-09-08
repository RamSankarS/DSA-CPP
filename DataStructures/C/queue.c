#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

typedef struct{
    int item[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue* q){
    q->front = -1;
    q->rear = 0;
}

bool isEmpty(Queue* q){ 
    return (q->front == q->rear - 1);
}

bool isFull(Queue* q){
    return (q->rear == MAX_SIZE);
}

void enque(Queue* q, int ele){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }
    q->item[q->rear++] = ele;
}

void dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    q->front++;
}

void peek(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("%d\n",q->item[q->front+1]);
}

void displayQueue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    for(int i = q->front + 1;i < q->rear; ++i){
        printf("%d ",q->item[i]);
    }
    printf("\n");
}

int main(){
    Queue q;
    Queue p;
    init(&q);
    printf("Initialized queue q\n");
    init(&p);
    printf("Initialized queue p\n");
    dequeue(&q);
    peek(&q);
    displayQueue(&q);
    enque(&q, 10);
    enque(&q, 20);
    enque(&q, 30);
    enque(&q, 40);
    displayQueue(&q);
    dequeue(&q);
    displayQueue(&q);
    dequeue(&q);
    displayQueue(&q);
    dequeue(&q);
    displayQueue(&q);
}
