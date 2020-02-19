cmake_minimum_required(VERSION 3.10)
project(MyC C)

set(CMAKE_C_STANDARD 99)

add_executable(MyC
        Playground.c
        DataStructure/SeqList.c
        DataStructure/SeqStack.h
        DataStructure/SeqStack.c
        DataStructure/DoublyLinkedList.c
        DataStructure/SinglyLinkedList.c
        DataStructure/DoublyLinkedList.h
        DataStructure/SeqList.h
        DataStructure/SinglyLinkedList.h
        Util/status_bool.h
        Util/status_bool.c
        Util/consoleutil.c
        Util/consoleutil.h
        DataStructure/LinkedStack.c
        DataStructure/LinkedStack.h
        DataStructure/BaseConvert.c
        Util/scanner.c
        Util/scanner.h
        DataStructure/BaseConvert.h DataStructure/CircularQueue.c DataStructure/CircularQueue.h datastructrue.h)