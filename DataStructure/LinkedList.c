//
// Created by carl- on 2020/2/7.
//

#include "stdio.h"
#include "stdlib.h"

typedef char Data;
typedef struct Node {
    Data data;
    struct Node *next;
} ListNode;

typedef ListNode *LinkList;

/***
 * 生成新节点
 * @return 新节点
 */
ListNode *newNode() {
    ListNode *pNode = (ListNode *) malloc(sizeof(ListNode));
    if (pNode){
        return pNode;
    }
    printf("节点申请失败");
    return NULL;
}

/***
 * 头插法建立单链表
 * @return head 单链表
 */
LinkList createListF() {
    Data ch;
    ListNode *pNode;
    LinkList pHead = NULL;
    printf("输入链表各个节点的顺序\n");
    while ((ch = getchar()) && ch != '\n') {
        pNode = newNode();
        if (pNode == NULL) {
            return NULL;
        }
        pNode->data = ch;
        pNode->next = pHead;
        pHead = pNode;
    }
    return pHead;
}

/***
 * 尾插法法建立单链表
 * @return 单链表
 */
LinkList createListE() {
    Data ch;
    ListNode *pNode, *pEndNode;
    LinkList linkHead = newNode();
    if (linkHead == NULL) {
        return NULL;
    }
    pEndNode = linkHead;
    printf("请输入链表各节点数据\n");
    while ((ch = getchar()) && ch != '\n') {
        pNode = newNode();
        if (pNode == NULL) {
            return NULL;
        }
        pNode->data = ch;
        pEndNode->next = pNode;
        pEndNode = pNode;

    }
    pEndNode->next = NULL;
    return linkHead;
}

/***
 * 查找第N个节点
 * @param head 链表的头节点
 * @param n 第N个节点
 * @return 找到的节点
 */
ListNode *getNodeN(LinkList head, int n) {
    int count = 1;
    ListNode *pNode = head->next;
    while (pNode && count < n) {
        pNode = pNode->next;
        count++;
    }
    if (count == n) {
        return pNode;
    } else {
        return NULL;
    }
}

/***
 * 按值查找节点
 * @param list 链表
 * @param data 值
 * @return 节点
 */
ListNode *locateNode(LinkList list, Data data){
    ListNode *pNode = list->next;
    while (pNode&& pNode->data!=data){
        pNode = pNode ->next;
    }
    return pNode;
}

/***
 * 获取链表长度
 * @param list 带头节点的单链表
 * @return 长度
 */
int getListLength(LinkList list) {
    ListNode *node = list->next;
    int length = 0;
    while (node) {
        node = node->next;
        length++;
    }
    return length;
}


int main() {
    
}
