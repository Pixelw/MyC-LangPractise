//
// Created by carl- on 2020/2/13.
//

#include <stdio.h>
#include "consoleutil.h"
#include "status_bool.h"

int on_success() {
    return OK;
}

int on_error(char *err_msg) {
    enum console_color red = Red;
    printf_in_color_win(red,str_joint("error occurred\n",err_msg));
    return ERROR;
}

int on_overflow(char *err_msg) {
    enum console_color red = Red;
    printf_in_color_win(red,str_joint("overflowed\n",err_msg));
    return OVERFLOW;
}

void *on_err_null(char *err_msg) {
    enum console_color red = Red;
    printf_in_color_win(red,str_joint("error occurred\n",err_msg));
    return NULL;
}

