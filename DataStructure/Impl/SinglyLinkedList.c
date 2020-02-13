//
// Created by carl- on 2020/2/7.
//

#include <stdio.h>
#include <stdlib.h>
#include "../SinglyLinkedList.h"
#include "../../Util/status_bool.h"

Node *makeNewNode() {
    Node *pNode = (Node *) malloc(sizeof(Node));
    if (pNode) {
        return pNode;
    }
    printf("malloc failed\n");
    return NULL;
}

LinkList createListF() {
    Data ch;
    LinkList pHead = makeNewNode();
    Node *pNode,*pPrevNode = NULL;
    printf("输入链表各个节点的数据(char)头插法\n");
    while ((ch = getchar()) && ch != '\n'){
        pNode = makeNewNode();
        if (pNode == NULL) {
            return NULL;
        }
        pNode->data = ch;
        pNode->next = pPrevNode;
        pPrevNode = pNode;
        pHead->next = pNode;
    }
    return pHead;
}

LinkList createListE() {
    Data ch;
    Node *pNode, *pEndNode;
    LinkList pHead = makeNewNode();
    if (pHead == NULL) {
        return NULL;
    }
    pEndNode = pHead;
    printf("输入链表各个节点的数据(char)尾插法\n");
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
    return pHead;
}

Node *getNodeN(LinkList head, int n) {
    int count = 0;
    Node *pNode = head;
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

int insertNode(LinkList list, Data data, int n) {
    Node *pPrevNode, *pNewNode;
    pPrevNode = getNodeN(list, n - 1);
    if (pPrevNode == NULL) {
        printf("the previous node of node_%d not found\n", n);
        return _ERROR;
    }
    pNewNode = makeNewNode();
    if (pNewNode == NULL) {
        return _ERROR;
    }
    pNewNode->data = data;
    pNewNode->next = pPrevNode->next;
    pPrevNode->next = pNewNode;
    return n;
}

Node *locateNode(LinkList list, Data data) {
    Node *pNode = list->next;
    while (pNode && pNode->data != data) {
        pNode = pNode->next;
    }
    return pNode;
}

int removeNodeN(LinkList list, int n) {
    Node *pTargetNode, *pPrevNode;
    pPrevNode = getNodeN(list, n - 1);
    if (pPrevNode == NULL) {
        printf("the previous node of node_%d not found\n", n);
        return _ERROR;
    }
    pTargetNode = pPrevNode->next;
    //跳过
    pPrevNode->next = pTargetNode->next;
    //释放
    free(pTargetNode);
    return n;
}

int locateNodePos(LinkList list, Data data) {
    Node *pNode = list->next;
    int i = 0;
    while (pNode && pNode->data != data) {
        i++;
        pNode = pNode->next;

    }
    return i;
}

int getListLength(LinkList list) {
    Node *node = list->next;
    int length = 0;
    while (node) {
        length++;
        node = node->next;
    }
    return length;
}

void destroyList(LinkList head) {
    Node *pA, *pB;
    pA = (Node *) head;
    while (pA) {
        pB = pA->next;
        free(pA);
        pA = pB;
    }
    head = NULL;
}

void printList(LinkList list) {
    Node *node = list->next;
    printf("LinkedList:");
    while (node) {
        printf(" %c", node->data);
        node = node->next;
    }
    printf(";\n");
}
