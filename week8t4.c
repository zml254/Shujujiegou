#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 4

typedef struct {
    int elem[QUEUE_SIZE];
    int front;
    int rear;
    int tag;
} Queue;

int initQueue(Queue *queue) {
    queue->tag = 0;
    queue->front = 0;
    queue->rear = 0;
    return 1;
}

int enQueue(Queue *queue, int a) {
    if (queue->front == queue->rear && queue->tag == 1) {
        return 0;
    }
    queue->elem[queue->rear++] = a;
    printf("%d  ", a);
    if (queue->rear >= QUEUE_SIZE) {
        queue->rear %= QUEUE_SIZE;
    }
    if (queue->front == queue->rear) {
        printf("Stack filled\n");
        queue->tag = 1;
    }
    return 1;
}

int deQueue(Queue *queue,int *de){
    if (queue->front == queue->rear && queue->tag == 0) {
        return 0;
    }
    *de = queue->elem[queue->front++];
    printf("%d  ", *de);
    if (queue->front >= QUEUE_SIZE) {
        printf("Stack empty\n");
        queue->front %= QUEUE_SIZE;
    }
    if (queue->front == queue->rear) {
        queue->tag = 0;
    }
    return 1;
}
int main(){
    int a;
    Queue queue;
    initQueue(&queue);
    enQueue(&queue, 1);
    enQueue(&queue, 2);
    enQueue(&queue, 3);
    enQueue(&queue, 4);
    enQueue(&queue, 5);
    deQueue(&queue, &a);
    deQueue(&queue, &a);
    deQueue(&queue, &a);
    deQueue(&queue, &a);
    deQueue(&queue, &a);
    return 1;
}
