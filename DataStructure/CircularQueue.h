//
// Created by carl- on 2020/2/17.
//

#ifndef MYC_CIRCULARQUEUE_H
#define MYC_CIRCULARQUEUE_H

#include "../Util/status_bool.h"

#define QUEUE_SIZE 4
typedef char Data;
typedef struct cirQueue{
    Data data[QUEUE_SIZE];
    int front;
    int rear;
    int count;
}CirQueue;

/**
 * 初始化和创建队列
 * @return 循环队列
 */
CirQueue *initCirQueue();

/**
 * 判断队空
 * @param q
 * @return Status
 */
Status isQueueEmpty(CirQueue *q);

/**
 * 判断队满
 * @param q
 * @return Status
 */
Status isQueueFull(CirQueue *q);

/**
 * 入队
 * @param q
 * @param data
 * @return  队尾
 */
int enQueue(CirQueue *q,Data data);
/**
 * 出队
 * @param q
 * @return 数据
 */
Data deQueue(CirQueue *q);

/**
 * 取队首
 * @param q
 * @return 数据
 */
Data getQueueFront(CirQueue *q);

/**
 * 打印队列
 * @param q
 */
void showCirQueue(CirQueue *q);

void testSuite_CircularQueue();


#endif //MYC_CIRCULARQUEUE_H
