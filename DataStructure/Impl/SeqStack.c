//
// Created by carl- on 2020/2/12.
//

#include <stdio.h>
#include "../SeqStack.h"

void initStack(SeqStack *s) {
    s->top = -1;
}

int isStackEmpty(SeqStack *s) {
    return s->top == -1;
}

int isStackFull(SeqStack *s) {
    return s->top == STACK_SIZE - 1;
}

Data getTop(SeqStack *s) {
    if (isStackEmpty(s)) {
        return -1;
    }
    Data data = s->data[s->top - 1];
    return data;
}

int push(SeqStack *s, Data data) {
    if (isStackFull(s)) {
        return -1;
    }
    s->data[++s->top] = data;
    return 1;

}

int pop(SeqStack *s, Data *e) {
    if (isStackEmpty(s)) {
        return -1;
    }
    s->top--;
    *e = s->data[s->top];
    return 1;
}

int getLength(SeqStack *s) {
    return s->top;
}

void clearStack(SeqStack *s) {
    s->top = -1;
}

void showStack(SeqStack *s) {
    if (!isStackEmpty(s)) {
        printf("Stack:");
        for (int i = 0; i <= s->top; i++) {
            printf(" %c", s->data[i]);
        }
    }
}
