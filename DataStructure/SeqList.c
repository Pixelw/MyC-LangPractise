#include <stdio.h>
#include <malloc.h>

#define LIST_SIZE 10

typedef char Data;

typedef struct SeqList {
    Data *base;
    int length;
    int size;
} SeqList;

/***
 * 初始化顺序表
 * @return 顺序表
 */
SeqList initSeqList() {
    int size = LIST_SIZE * sizeof(Data);
    Data *base = (Data *) malloc(LIST_SIZE * sizeof(Data));
    int length = 0;
    SeqList seqList = {base, length, size};
    return seqList;
}

/**
 * 扩展顺序表的大小
 * @param list
 * @return 扩展后的大小（bytes）
 */
int extendList(SeqList *list) {
    Data *newBase = (Data *) realloc(list->base, (list->size + LIST_SIZE * sizeof(Data)));
    if (!newBase) {
        return -1;
    }
    list->base = newBase;
    list->size += LIST_SIZE;
    return list->size;
}

/**
 * 从输入充值顺序表
 * @param l
 * @return 输入后的长度
 */
int reInputList(SeqList *l) {
    printf("Input the data for this SeqList\n");
    Data ch;
    int position = 0;
    l->length = 0;
    while ((ch = getchar()) && ch != '\n') {
        if (l->length * sizeof(ch) >= l->size) {
            if (extendList(l) < 0){
                return -1;
            }
        }
        *(l->base + position)= ch;
        l->length++;
        position++;
    }
    return l->length;
}

/**
 * 插入到顺序表
 * @param list 表
 * @param data 数据
 * @param position 位置
 * @return 插入过后的位置
 */
int insertList(SeqList *list, Data data, int position) {
    if (position < 0 || position > list->length + 1) {
        return -1;
    }
    //如果顺序表空间不够，扩充新的空间
    if (list->length * sizeof(data) >= list->size) {
        if (extendList(list)<=0){
            return -1;
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

/**
 * 打印顺序表
 * @param l 表
 */
void showList(SeqList *l){
    printf("SeqList:");
    for (int i = 0; i < l->length; i++) {
        printf(" %c", *(l->base + i));
    }
    printf(";\n");
}

int main() {
    SeqList list = initSeqList();
    SeqList *l = &list;
    reInputList(l);
    showList(l);

}