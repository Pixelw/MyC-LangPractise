//
// Created by carl- on 2020/2/13.
//

#include <stdio.h>
#include <windows.h>

int onSuccess() {
    return 0;
}

int onError() {
    HANDLE handleConsole;
    handleConsole =GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    WORD savedAttr;
    //save current state before changes
    GetConsoleScreenBufferInfo(handleConsole,&consoleScreenBufferInfo);
    savedAttr = consoleScreenBufferInfo.wAttributes;
    //4 for red
    SetConsoleTextAttribute(handleConsole,4);
    printf("error occurred\n");
    //restore changes
    SetConsoleTextAttribute(handleConsole,savedAttr);
    return -1;
}

int onOverflow() {
    printf("overflowed\n");
    return -2;
}

