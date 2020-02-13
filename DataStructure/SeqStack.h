//
// Created by carl- on 2020/2/12.
//

#ifndef DATASTRUCTURE_SEQSTACK_H
#define DATASTRUCTURE_SEQSTACK_H

#define STACK_SIZE 5
typedef char Data;
typedef struct {
    Data data[STACK_SIZE];  //stored with array
    int top;    //the index of stack(aka array)
} SeqStack;

/**
 * 初始化栈
 * @param s 栈
 */
void initStack(SeqStack *s);
/***
 * 判断栈是否空
 * @param s 栈
 * @return 是返回1，不是返回0
 */
int isStackEmpty(SeqStack *s);

/**
 * 判断栈是否满
 * @param s 栈
 * @return 是返回1，不是返回0
 */
int isStackFull(SeqStack *s);

/**
 * 获取栈顶元素
 * @param s 栈
 * @return 返回数据
 */
Data getTop(SeqStack *s);

/**
 * 元素进栈
 * @param s 栈
 * @param data 入栈的数据
 * @return 成功返回1，失败返回-1
 */
int push(SeqStack *s, Data data);


//int pop(SeqStack *s, Data *data);

/**
 * 元素出栈
 * @param s 栈
 * @return
 */
int pop(SeqStack *s);

/**
 * 获取栈长度
 * @param s
 * @return 长度
 */
int getLength(SeqStack *s);

/**
 * 清除栈（重设top值）
 * @param s
 */
void clearStack(SeqStack *s);

/**
 * 打印栈
 * @param s
 */
void showStack(SeqStack *s);

#endif
