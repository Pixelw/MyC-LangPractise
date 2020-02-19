//
// Created by carl- on 2020/2/17.
//

#include "CircularQueue.h"
#include <stdlib.h>
#include <stdio.h>

CirQueue *initCirQueue() {
    CirQueue *q = malloc(sizeof(CirQueue));
    q->front = q->rear = q->count = 0;
    return q;
}

Status isQueueEmpty(CirQueue *q) {
    return q->count == 0;
}

Status isQueueFull(CirQueue *q) {
    return q->count == QUEUE_SIZE;
}

int enQueue(CirQueue *q, Data data) {
    if (isQueueFull(q)) {
        return on_error("queue is full\n");
    }
    q->count++;
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    return q->rear;
}

Data deQueue(CirQueue *q) {
    if (isQueueEmpty(q)) {
        return on_error("queue is empty\n");
    }
    Data data = q->data[q->front];
    q->count--;
    q->front = (q->front + 1) % QUEUE_SIZE;
    return data;
}

Data getQueueFront(CirQueue *q) {
    if (isQueueEmpty(q)) {
        return on_error("queue is empty");
    }
    return q->data[q->front];
}

void showCirQueue(CirQueue *q) {
    printf("CirQueue:");
    int offset = q->front;
    for (int i = 1; i <= q->count; ++i) {
        if (offset == QUEUE_SIZE){ //when limit exceed, back to 0
            offset = 0;
        }
        printf(" %c", q->data[offset]);
        offset++;
    }
    printf("\nFront=%d, Rear=%d, Count=%d\n", q->front, q->rear, q->count);
}

void testSuite_CircularQueue() {
    CirQueue *q = initCirQueue();
    enQueue(q, 'a');
    enQueue(q, 'b');
    enQueue(q, 'c');
    enQueue(q, 'd');
    printf("%c\n", deQueue(q));
    printf("%c\n", deQueue(q));
    printf("%c\n", deQueue(q));
    enQueue(q, 'e');
    enQueue(q, 'a');
    enQueue(q, 'b');
    showCirQueue(q);
}






