//
// Created by carl- on 2020/2/13.
//

#include <stdio.h>
#include "consoleutil.h"
#include "status_bool.h"

int on_success() {
    return OK;
}

int on_error() {
    enum console_color red = Red;
    printf_in_color_win(red, "error occurred\n");
    return ERROR;
}

int on_overflow() {
    printf("overflowed\n");
    return OVERFLOW;
}

