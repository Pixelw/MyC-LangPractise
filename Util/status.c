//
// Created by carl- on 2020/2/13.
//

#include <stdio.h>
#include "printincolor.h"

int on_success() {
    return 0;
}

int on_error() {
    enum console_color red = Red;
    printf_in_color_win(red, "error occurred\n");
    return -1;
}

int on_overflow() {
    printf("overflowed\n");
    return -2;
}

