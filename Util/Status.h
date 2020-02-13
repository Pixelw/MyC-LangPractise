//
// Created by carl- on 2020/2/13.
//

#ifndef DATASTRUCTURE_STATUS_H
#define DATASTRUCTURE_STATUS_H

#define OK onSuccess()  //0
#define ERROR onError() //-1
#define OVERFLOW onOverflow() //-2

int onSuccess();

/**
 * 在return ERROR时，输出错误，换用红色字体(windows)
 * @return -1
 */
int onError();

int onOverflow();

#endif //DATASTRUCTURE_STATUS_H
