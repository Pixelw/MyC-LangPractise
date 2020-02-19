//
// Created by carl- on 2020/2/13.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"
#include "../Util/status_bool.h"

LinkedStack* initLStack() {
    LinkedStack *s = (LinkedStack *) malloc(sizeof(LinkedStack));
    s->top = NULL;  //置栈空
    return s;
}

int isLStackEmpty(LinkedStack *s) {
    if (s->top == NULL) {
//        printf("empty stack\n");
        return 1;
    }
    return 0;
}

int pushLS(LinkedStack *s, Data data) {
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    if (!node) {
        printf("malloc failed\n");
        return _ERROR;
    }
    node->data = data;
    node->prev = s->top;
    s->top = node;
    return OK;
}

Data popLS(LinkedStack *s) {
    if (isLStackEmpty(s)) {
        return _ERROR;
    }
    StackNode *node = s->top;
    Data data = node->data;
    s->top = node->prev;
    free(node);
    return data;
}

Data getLStackTop(LinkedStack *s) {
    if (isLStackEmpty(s)) {
        return _ERROR;
    }
    return s->top->data;
}

void showLStack(LinkedStack *s) {
    if (isLStackEmpty(s)) {
        printf("This stack is empty\n");
    } else {
        StackNode *node = s->top;
        for (int i = 0; node; ++i) { //while node(node's prev is not null)
            printf("%d\t%c\n", i, node->data);
            node = node->prev;
        }
        printf("\n");
    }
}

void DestroyLStack(LinkedStack *s) {
    StackNode *node = s->top;
    while (node) {
        s->top = node->prev;
        free(node);
        node = s->top;
    }
//    free(s->top);
    free(s);
    printf("wwww\n");
}



