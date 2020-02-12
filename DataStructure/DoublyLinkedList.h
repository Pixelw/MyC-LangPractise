//
// Created by carl- on 2020/2/12.
//

#ifndef DATASTRUCTURE_DOUBLYLINKEDLIST_H
#define DATASTRUCTURE_DOUBLYLINKEDLIST_H

typedef char Data;
typedef struct dlnode {
    Data data;
    struct dlnode *prior, *next;
} DLNode;

typedef DLNode *DLinkList;


/**
 * 建立新节点
 * @return 节点
 */
DLinkList makeNewDLNode();


/**
 * 创建列表（尾插法）
 * @return
 */
DLinkList createDListE();

/**
 * 取得第N个节点
 * @param list
 * @param n
 * @return 节点
 */
DLNode *getDLNodeN(DLinkList list, int n);


/**
 * 插入节点到N
 * @param list
 * @param data 数据（char）
 * @param n
 * @return
 */
int insertDLNode(DLinkList list, Data data, int n);

/**
 * 删除第N节点
 * @param list
 * @param n
 */
void deleteDLNode(DLinkList list, int n);

/**
 * 答应整个链表
 * @param list
 */
void printDLList(DLinkList list);


#endif //DATASTRUCTURE_DOUBLYLINKEDLIST_H
