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
 * �����½ڵ�
 * @return �½ڵ�
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
 * ͷ�巨����������
 * @return head ������
 */
LinkList createListF() {
    Data ch;
    LinkList pHead = makeNewNode();
    Node *pNode,*pPrevNode = NULL;
    printf("������������ڵ������(char)ͷ�巨\n");
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

/***
 * β�巨����������
 * @return ������
 */
LinkList createListE() {
    Data ch;
    Node *pNode, *pEndNode;
    LinkList pHead = makeNewNode();
    if (pHead == NULL) {
        return NULL;
    }
    pEndNode = pHead;
    printf("������������ڵ������(char)β�巨\n");
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

/***
 * ���ҵ�N���ڵ�
 * @param head �����ͷ�ڵ�
 * @param n
 * @return �ҵ��Ľڵ�
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
 * ��ֵ���ҽڵ�
 * @param list ����
 * @param data ֵ
 * @return �ڵ�
 */
Node *locateNode(LinkList list, Data data) {
    Node *pNode = list->next;
    while (pNode && pNode->data != data) {
        pNode = pNode->next;
    }
    return pNode;
}

/***
 * ��ֵ���ҳ�data����λ��
 * @param list
 * @param data
 * @return λ��
 */
int locateNodePos(LinkList list, Data data) {
    Node *pNode = list->next;
    int i = 0;
    while (pNode && pNode->data != data) {
        i++;
        pNode = pNode->next;

    }
    return i;
}

/***
 * ��ȡ������
 * @param list ��ͷ�ڵ�ĵ�����
 * @return ����
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
 * �����½ڵ㵽 n
 * @param list ����
 * @param data ���������
 * @param n
 * @return �ɹ��򷵻ز����λ�� @param n
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
 * ɾ���� n ���ڵ�
 * @param list ����
 * @param n
 * @return �ɹ��򷵻�ɾ����λ�� @param n
 */
int removeNodeN(LinkList list, int n) {
    Node *pTargetNode, *pPrevNode;
    pPrevNode = getNodeN(list, n - 1);
    if (pPrevNode == NULL) {
        printf("the previous node of node_%d not found\n", n);
        return FAILED;
    }
    pTargetNode = pPrevNode->next;
    //����
    pPrevNode->next = pTargetNode->next;
    //�ͷ�
    free(pTargetNode);
    return n;
}

/***
 * ��������
 * @param head ����ͷ�ڵ㣩
 */
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

int main() {
    LinkList l2 = createListF();
    printList(l2);

//    destroyList(l);
//    printList(l);

}
