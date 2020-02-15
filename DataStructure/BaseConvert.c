//
// Created by carl- on 2020/2/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"
#include "SeqList.h"
#include "../Util/status_bool.h"

char *baseConvert(long long number, int base) {
    if (base < 2 || base > 16) {
        return _ERRNULL;
    }
    if (number == 0) {
        return "0";
    }
    LinkedStack *ls = initLStack();
    if (!ls) {
        printf("malloc failed\n");
        return _ERRNULL;
    }
    while (number) {  //while number != 0
        if (pushLS(ls, number % base)) {
            number = number / base;
        }
    }
    SeqList seqList = initSeqList(12);
    SeqList *result = &seqList;
    while (!isLStackEmpty(ls)) {
        int raw = popLS(ls);   //number is stored in data(char)
        if (raw >= 0 && raw < 10) {    //convert int to char
            raw += 48; //ASCII 0~9==48~57
        } else if (raw > 10 && raw <= 15) {
            raw += 87; //ASCII a~f==97~102
        } else {
            return _ERRNULL;
        }
        appendSL(result, raw);    //append converted char into SeqList (similar to char[])
    }
    return toCharArray(result);
}