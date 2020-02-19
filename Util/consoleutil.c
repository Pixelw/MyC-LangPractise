//
// Created by carl- on 2020/2/13.
//

#include "consoleutil.h"
#include <stdio.h>
#include <windows.h>

void printf_in_color_win(enum console_color color, char *str) {
    HANDLE handleConsole;
    handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    WORD savedAttr;
    //save current state before changes
    GetConsoleScreenBufferInfo(handleConsole, &bufferInfo);
    savedAttr = bufferInfo.wAttributes;
    //set attrs and print
    SetConsoleTextAttribute(handleConsole, color);
    printf("%s", str);
    //restore changes
    SetConsoleTextAttribute(handleConsole, savedAttr);
}

void printf_in_red_ansi(char *str) {
    printf("\033[0;31m");
    printf("%s", str);
    printf("\033[0m");
}

char *str_joint(char *a, char *b) {
    char *joint = (char *)malloc(strlen(a)+strlen(b));
    sprintf(joint,"%s%s",a,b);
    return joint;
}