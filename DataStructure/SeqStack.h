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
void initSStack(SeqStack *s);
/***
 * 判断栈是否空
 * @param s 栈
 * @return 是返回1，不是返回0
 */
int isSStackEmpty(SeqStack *s);

/**
 * 判断栈是否满
 * @param s 栈
 * @return 是返回1，不是返回0
 */
int isSStackFull(SeqStack *s);

/**
 * 获取栈顶元素
 * @param s 栈
 * @return 返回数据
 */
Data getSStackTop(SeqStack *s);

/**
 * 元素进栈
 * @param s 栈
 * @param data 入栈的数据
 * @return 成功返回1，失败返回-1
*/
int pushSS(SeqStack *s, Data data);


//int pop(SeqStack *s, Data *data);

/**
 * 元素出栈
 * @param s 栈
 * @return 出栈的元素
 */
Data popSS(SeqStack *s);

/**
 * 获取栈长度
 * @param s
 * @return 长度
 */
int getSSLength(SeqStack *s);

/**
 * 清除栈（重设top值）
 * @param s
 */
void clearSStack(SeqStack *s);

/**
 * 打印栈
 * @param s
 */
void showSStack(SeqStack *s);

#endif
