//
// Created by carl- on 2020/2/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "../DoublyLinkedList.h"
#include "../../Util/Status.h"

DLinkList makeNewDLNode() {
    DLNode *pNode = (DLNode *) malloc(sizeof(DLNode));
    if (pNode) {
        return pNode;
    }
    printf("malloc failed\n");
    return NULL;
}

DLinkList createDListE() {
    Data ch;
    DLNode *pNode, *pEndNode;
    DLinkList pHead = makeNewDLNode();
    if (!pHead) {
        return NULL;
    }
    pEndNode = pHead;
    printf("Input the data for this DLList\n");
    while ((ch = getchar()) && ch != '\n') {
        pNode = makeNewDLNode();
        if (!pNode) {
            return NULL;
        }
        pNode->data = ch;
        if (pEndNode == pHead) {
            pNode->prior = NULL;
        } else {
            pNode->prior = pEndNode;
        }
        pEndNode->next = pNode;
        pEndNode = pNode;

    }
    pEndNode->next = NULL;
    return pHead;
}

DLNode *getDLNodeN(DLinkList list, int n) {
    int count = 0;
    DLNode *pNode = list;
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

int insertDLNode(DLinkList list, Data data, int n) {
    DLNode *pNewNode = makeNewDLNode(), *pPrevNode;
    pPrevNode = getDLNodeN(list, n - 1);
    if (!pPrevNode) {
        printf("the previous node of node_%d not found\n", n);
        return ERROR;
    }
    pNewNode->data = data;
    pNewNode->next = pPrevNode->next;
    pNewNode->next->prior = pNewNode;
    pPrevNode->next = pNewNode;
    if (pPrevNode != list) {
        pNewNode->prior = pPrevNode;
    }
    return n;
}

void deleteDLNode(DLinkList list, int n) {
    DLNode *pNode = getDLNodeN(list, n);
    if (!pNode->prior) {
        list->next = pNode->next;
    }
    if (pNode->next) {
        pNode->next->prior = pNode->prior;
    }

    free(pNode);
}

void printDLList(DLinkList list) {
    DLNode *node = list->next;
    printf("DoublyLinkedList:");
    while (node) {
        printf(" %c", node->data);
        node = node->next;
    }
    printf(";\n");
}

