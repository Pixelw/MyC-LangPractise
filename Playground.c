
#include "DataStructure/SinglyLinkedList.h"
#include "DataStructure/SeqStack.h"

int main() {
    LinkList list = createListF();
    printList(list);
    SeqStack seqStack = {{'1', '2', '3', '4', '5'}, 4};
    push(&seqStack, '9');
    showStack(&seqStack);
}
