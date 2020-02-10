//
// Created by carl- on 2020/2/7.
//

#include "stdio.h"
#include "stdlib.h"

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
Node *makeNewNode() {
    Node *pNode = (Node *) malloc(sizeof(Node));
    if (pNode) {
        return pNode;
    }
    printf("malloc failed\n");
    return NULL;
}

/***
 * 头插法建立单链表
 * @return head 单链表
 */
 //TODO bug
LinkList createListF() {
    Data ch;
    Node *pNode;
    LinkList pHead = NULL;
    printf("输入链表各个节点的数据(char)\n");
    while ((ch = getchar()) && ch != '\n') {
        pNode = makeNewNode();
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
 * 尾插法建立单链表
 * @return 单链表
 */
LinkList createListE() {
    Data ch;
    Node *pNode, *pEndNode;
    LinkList linkHead = makeNewNode();
    if (linkHead == NULL) {
        return NULL;
    }
    pEndNode = linkHead;
    printf("输入链表各个节点的数据(char)\n");
    while ((ch = getchar()) && ch != '\n') {
        pNode = makeNewNode();
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
 * @param n
 * @return 找到的节点
 */
Node *getNodeN(LinkList head, int n) {
    int count = 1;
    Node *pNode = head->next;
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
Node *locateNode(LinkList list, Data data) {
    Node *pNode = list->next;
    while (pNode && pNode->data != data) {
        pNode = pNode->next;
    }
    return pNode;
}

int locateNodePos(LinkList list, Data data){
    Node *pNode = list->next;
    int i = 0;
    while (pNode && pNode->data != data) {
        i ++;
        pNode = pNode->next;

    }
    return i;
}

/***
 * 获取链表长度
 * @param list 带头节点的单链表
 * @return 长度
 */
int getListLength(LinkList list) {
    Node *node = list->next;
    int length = 0;
    while (node) {
        length++;
        node = node->next;
    }
    return length;
}

/***
 * 插入新节点到 n
 * @param list 链表
 * @param data 插入的数据
 * @param n
 * @return 成功则返回插入的位置 @param n
 */
int insertNode(LinkList list, Data data, int n) {
    Node *pPrevNode, *pNewNode;
    pPrevNode = getNodeN(list, n - 1);
    if (pPrevNode == NULL) {
        printf("the previous node of node_%d not found\n", n);
        return FAILED;
    }
    pNewNode = makeNewNode();
    if (pNewNode == NULL) {
        return FAILED;
    }
    pNewNode->data = data;
    pNewNode->next = pPrevNode->next;
    pPrevNode->next = pNewNode;
    return n;
}

/***
 * 删除第 n 个节点
 * @param list 链表
 * @param n
 * @return 成功则返回删除的位置 @param n
 */
int removeNodeN(LinkList list, int n){
    Node *pTargetNode, *pPrevNode;
    pPrevNode = getNodeN(list, n - 1);
    if (pPrevNode == NULL) {
        printf("the previous node of node_%d not found\n", n);
        return FAILED;
    }
    pTargetNode = pPrevNode->next;
    //跳过
    pPrevNode->next = pTargetNode->next;
    //释放
    free(pTargetNode);
    return n;
}

/***
 * 销毁链表
 * @param head 链表（头节点）
 */
void destroyList(LinkList head){
     Node *pA, *pB;
     pA = (Node *)head;
    while(pA){
        pB = pA->next;
        free(pA);
        pA = pB;
    }
    head = NULL;
}

void printList(LinkList list){
    Node *node = list ->next;
    printf("LinkedList:");
    while (node){
        printf(" %c",node->data);
        node = node->next;
    }
    printf(";\n");

}

int main() {
    LinkList l = createListE();
    printList(l);
    printf("%d\n",getListLength(l));
//    Node *node = getNodeN(linkList, 3);
//    printf("3 is %c",node->data);
    insertNode(l, 's', 2);
    printList(l);
    Node *node;
    node = locateNode(l, '-');
    if (node){
        printf("%c",node->data);
    }
    removeNodeN(l, 3);
    printList(l);
//    destroyList(l);
//    printList(l);

}
