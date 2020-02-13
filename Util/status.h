//
// Created by carl- on 2020/2/13.
//

#ifndef DATASTRUCTURE_STATUS_H
#define DATASTRUCTURE_STATUS_H

#define OK on_success()  //0
#define ERROR on_error() //-1
#define OVERFLOW on_overflow() //-2

int on_success();

/**
 * 在return ERROR时，输出错误，换用红色字体(windows)
 * @return -1
 */
int on_error();

int on_overflow();

#endif //DATASTRUCTURE_STATUS_H
