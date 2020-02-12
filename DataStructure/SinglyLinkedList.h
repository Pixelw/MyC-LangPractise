//
// Created by carl- on 2020/2/12.
//

#ifndef DATASTRUCTURE_SINGLYLINKEDLIST_H
#define DATASTRUCTURE_SINGLYLINKEDLIST_H

#define FAILED -1

typedef char Data;
typedef struct ListNode {
    Data data;
    struct ListNode *next;
} Node;

typedef Node *LinkList;

/***
 * 生成新节点
 * @return 新节点
 */
Node *makeNewNode();

/***
 * 头插法建立单链表
 * @return head 单链表
 */
LinkList createListF();

/***
 * 尾插法建立单链表
 * @return 单链表
 */
LinkList createListE();

/***
 * 查找第N个节点
 * @param head 链表的头节点
 * @param n
 * @return 找到的节点
 */
Node *getNodeN(LinkList head, int n);

/***
 * 按值查找节点
 * @param list 链表
 * @param data 值
 * @return 节点
 */
Node *locateNode(LinkList list, Data data);

/***
 * 按值查找出data所在位置
 * @param list
 * @param data
 * @return 位置
 */
int locateNodePos(LinkList list, Data data);

/***
 * 获取链表长度
 * @param list 带头节点的单链表
 * @return 长度
 */
int getListLength(LinkList list);

/***
 * 插入新节点到 n
 * @param list 链表
 * @param data 插入的数据
 * @param n
 * @return 成功则返回插入的位置 @param n
 */
int insertNode(LinkList list, Data data, int n);

/***
 * 删除第 n 个节点
 * @param list 链表
 * @param n
 * @return 成功则返回删除的位置 @param n
 */
int removeNodeN(LinkList list, int n);

/***
 * 销毁链表
 * @param head 链表（头节点）
 */

void destroyList(LinkList head);

/***
 * 打印list
 * @param list 链表
 */
void printList(LinkList list);


#endif //DATASTRUCTURE_SINGLYLINKEDLIST_H
