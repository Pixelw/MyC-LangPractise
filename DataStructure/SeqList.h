//
// Created by carl- on 2020/2/12.
//

#ifndef DATASTRUCTURE_SEQLIST_H
#define DATASTRUCTURE_SEQLIST_H

//#define LIST_SIZE 10

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
SeqList initSeqList(int initsize);


/**
 * 扩展顺序表的大小
 * @param list
 * @return 扩展后的大小（bytes）
 */
int extendList(SeqList *list);

/**
 * 从输入充值顺序表
 * @param l
 * @return 输入后的长度
 */
int reInputList(SeqList *l);

/**
 * 插入到顺序表
 * @param list 表
 * @param data 数据
 * @param position 位置
 * @return 插入过后的位置
 */
int insertList(SeqList *list, Data data, int position);

/**
 * 追加Data（字符）
 * @param l
 * @param data
 * @return
 */
int appendSL(SeqList *l, Data data);

/**
 * 删除第N个数据
 * @param l 顺序表
 * @param n
 * @return 成功返回长度
 */
int deleteList(SeqList *l, int n);

/**
 * 获取第n个数据
 * @param l 顺序表
 * @param position 位置
 * @return 值
 */
Data getDataN(SeqList *l, int position);


/**
 * 打印顺序表
 * @param l 表
 */
void showList(SeqList *l);

/**
 * 返回为字符串（指针）
 * @param l 顺序表
 * @return 字符指针用\0截断
 */
char* toCharArray(SeqList *l);

#endif //DATASTRUCTURE_SEQLIST_H
