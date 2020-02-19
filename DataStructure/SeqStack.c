//
// Created by carl- on 2020/2/12.
//

#include <stdio.h>
#include "SeqStack.h"
#include "../Util/status_bool.h"

void initSStack(SeqStack *s) {
    s->top = -1;
}

int isSStackEmpty(SeqStack *s) {
    return s->top == -1;
}

int isSStackFull(SeqStack *s) {
    return s->top == STACK_SIZE - 1;
}

Data getSStackTop(SeqStack *s) {
    if (isSStackEmpty(s)) {
        printf("empty stack\n");
        return _ERROR;
    }
    Data data = s->data[s->top - 1];
    return data;
}

int pushSS(SeqStack *s, Data data) {
    if (isSStackFull(s)) {
        printf("full stack\n");
        return _ERROR;
    }
    s->data[++s->top] = data;
    return s->top;
}

//int pop(SeqStack *s, Data *data) {
//    if (isSStackEmpty(s)) {
//        return ERROR;
//    }
//    s->top--;
//    *data = s->data[s->top];
//    return 1;
//}
Data popSS(SeqStack *s) {
    if (isSStackEmpty(s)) {
        printf("empty stack\n");
        return _ERROR;
    }
    Data data = s->top;
    s->top--;
    return data;
}

int getSSLength(SeqStack *s) {
    return s->top;
}

void clearSStack(SeqStack *s) {
    s->top = -1;
}

void showSStack(SeqStack *s) {
    if (!isSStackEmpty(s)) {
        printf("Stack:");
        for (int i = 0; i <= s->top; i++) {
            printf(" %c", s->data[i]);
        }
    }
}

