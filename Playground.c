#include "DataStructure/SinglyLinkedList.h"
#include "DataStructure/SeqStack.h"

int main() {
    SeqStack seqStack = {{'1', '2', '3', '4','6'}, 4};
    push(&seqStack, '9');
    showStack(&seqStack);
}
