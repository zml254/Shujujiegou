#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 4

typedef struct elem{
    char content;
    int tag;
}Elem;

typedef struct queue {
    Elem elem[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

int initQueue(Queue *queue){//��ʼ��,������Ԫ�ض����Ϊ0
    int i;
    for (i = 0; i < QUEUE_SIZE; i++) {
        queue->elem[i].tag = 0;
    }
    queue->front = 0;
    queue->rear = 0;
}

int enQueue(Queue *queue, char en) {//���Ԫ��
    int a;
    a = queue->rear;
    if (queue->elem[a].tag == 0) {//�ж���һ���Ƿ����Ƿ�Ϊ0,Ϊ0���������
        queue->elem[a].tag = 1;
        queue->elem[a].content = en;
        if (++queue->rear >= QUEUE_SIZE) {//�ж�ָ���Ƿ񳬹�����
            queue->rear %= QUEUE_SIZE;
        }
    }
    return 1;
}

int deQueue(Queue *queue, char *de) {
    int a;
    a = queue->front;
    if (queue->elem[a].tag == 1) {//�жϵ�ǰ�Ƿ���Ϊ1,Ϊ1��������
        queue->elem[a].tag = 0;
        *de = queue->elem[a].content;
        if (++a >= QUEUE_SIZE) {//�ж��Ƿ񳬹�����
            a %= QUEUE_SIZE;
        }
        queue->front = a;
    }
    return 1;
}

int main(){
    Queue queue;
    char a = '\0';
    initQueue(&queue);
    enQueue(&queue, 'w');
    enQueue(&queue, 'e');
    enQueue(&queue, 'a');
    enQueue(&queue, 'r');
    enQueue(&queue, 'e');
    deQueue(&queue, &a);
    printf("%c\n", a);
    a = '\0';
    deQueue(&queue, &a);
    printf("%c\n", a);
    a = '\0';
    deQueue(&queue, &a);
    printf("%c\n", a);
    a = '\0';
    deQueue(&queue, &a);
    printf("%c\n", a);
    a = '\0';
    deQueue(&queue, &a);
    printf("%c\n", a);
}
