cmake_minimum_required(VERSION 3.15)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructure
        Playground.c
        DataStructure/Impl/SeqList.c
        DataStructure/SeqStack.h
        DataStructure/Impl/SeqStack.c
        DataStructure/Impl/DoublyLinkedList.c
        DataStructure/Impl/SinglyLinkedList.c
        DataStructure/DoublyLinkedList.h
        DataStructure/SeqList.h
        DataStructure/SinglyLinkedList.h Util/status.h Util/status.c Util/printincolor.c Util/printincolor.h)