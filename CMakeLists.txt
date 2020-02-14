cmake_minimum_required(VERSION 3.15)
project(MyC C)

set(CMAKE_C_STANDARD 99)

add_executable(MyC
        Playground.c
        DataStructure/Impl/SeqList.c
        DataStructure/SeqStack.h
        DataStructure/Impl/SeqStack.c
        DataStructure/Impl/DoublyLinkedList.c
        DataStructure/Impl/SinglyLinkedList.c
        DataStructure/DoublyLinkedList.h
        DataStructure/SeqList.h
        DataStructure/SinglyLinkedList.h
        Util/status_bool.h
        Util/status_bool.c
        Util/consoleutil.c
        Util/consoleutil.h
        DataStructure/Impl/LinkedStack.c
        DataStructure/LinkedStack.h
        DataStructure/BaseConvert.c
        Util/scanner.c
        Util/scanner.h)