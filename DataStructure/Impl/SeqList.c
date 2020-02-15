#include <stdio.h>
#include <malloc.h>
#include "../SeqList.h"
#include "../../Util/status_bool.h"

SeqList initSeqList(int initsize) {
    int size = initsize * sizeof(Data);
    Data *base = (Data *) malloc(initsize * sizeof(Data));
    int length = 0;
    SeqList seqList = {base, length, size};
    return seqList;
}

int extendList(SeqList *list) {
    Data *newBase = (Data *) realloc(list->base, (list->size + 10 * sizeof(Data)));
    if (!newBase) {
        return _ERROR;
    }
    list->base = newBase;
    list->size += 10;
    return list->size;
}

int reInputList(SeqList *l) {
    printf("Input the data for this SeqList\n");
    Data ch;
    int position = 0;
    l->length = 0;
    while ((ch = getchar()) && ch != '\n') {
        if (l->length * sizeof(ch) >= l->size) {
            if (extendList(l) < 0) {
                return _ERROR;
            }
        }
        //incompatible with pointer
        *(l->base + position) = ch;
        l->length++;
        position++;
    }
    return l->length;
}

int insertList(SeqList *list, Data data, int position) {
    if (position < 0 || position > list->length + 1) {
        return _ERROR;
    }
    //如果顺序表空间不够，扩充新的空间
    if (list->length * sizeof(data) >= list->size) {
        if (extendList(list) <= 0) {
            return _ERROR;
        }
    }
    //插入后移
    Data *p;
    for (p = list->base + list->length - 1; p >= list->base + position; p--) {
        *(p + 1) = *p;
    }
    //写入数据
    *(list->base + position) = data;
    list->length++;
    return position;
}

int deleteList(SeqList *l, int n) {
    if (n < 1 || n > l->length || n > l->size) {
        return _ERROR;
    }
    Data *p;
    for (p = l->base + n - 1; p < l->base + l->length; p++) {
        *p = *(p + 1);
    }
    l->length--;
    return l->length;
}

void showList(SeqList *l) {
    printf("SeqList:");
    for (int i = 0; i < l->length; i++) {
        printf(" %c", *(l->base + i));
    }
    printf(";\n");
}

Data getDataN(SeqList *l, int position) {
    return *(l->base + position);
}

int appendSL(SeqList *l, Data data) {
    if (l->length * sizeof(data) >= l->size) {
        if (extendList(l) <= 0) {
            return _ERROR;
        }
    }
    *(l->base + l->length) = data;
    l->length++;
    return l->length;
}

char *toCharArray(SeqList *l) {
    appendSL(l,'\0');   //cut seqlist
    return l->base; //then return
}
