//
// Created by carl- on 2020/2/13.
//

#ifndef DATASTRUCTURE_LINKEDSTACK_H

typedef char Data;
typedef struct stacknode{
    Data data;
    struct stacknode *prev; //or call it next, whatever
}StackNode;

typedef struct{
    StackNode *top; //栈顶指针
}LinkedStack;

/**
 * 初始化栈
 * @param s 栈
 */
LinkedStack initLStack();
/***
 * 判断栈是否空
 * @param s 栈
 * @return 是返回1，不是返回0
 */
int isLStackEmpty(LinkedStack *s);

/**
 * 元素进栈
 * @param s 栈
 * @param data 入栈的数据
 * @return 成功返回1，失败返回-1
*/
int pushLS(LinkedStack *s, Data data);

/**
 * 元素出栈
 * @param s 栈
 * @return 出栈的元素
 */
Data popLS(LinkedStack *s);

/**
 * 获取栈顶元素
 * @param s 栈
 * @return 返回数据
 */
Data getLStackTop(LinkedStack *s);

void showLStack(LinkedStack *s);

#define DATASTRUCTURE_LINKEDSTACK_H

#endif //DATASTRUCTURE_LINKEDSTACK_H
