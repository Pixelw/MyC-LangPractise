//
// Created by carl- on 2020/2/12.
//

#ifndef DATASTRUCTURE_SEQSTACK_H
#define DATASTRUCTURE_SEQSTACK_H

#define STACK_SIZE 100
typedef char Data;
typedef struct {
    Data data[STACK_SIZE];  //stored with array
    int top;    //the index of stack(aka array)
} SeqStack;

void initStack(SeqStack *s);

int isStackEmpty(SeqStack *s);

int isStackFull(SeqStack *s);

Data getTop(SeqStack *s);

int push(SeqStack *s, Data data);

int pop(SeqStack *s, Data *e);

int getLength(SeqStack *s);

void clearStack(SeqStack *s);

void showStack(SeqStack *s);

#endif
