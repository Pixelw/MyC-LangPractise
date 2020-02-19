//
// Created by carl- on 2020/2/14.
//
#include <stdio.h>
#include "LinkedStack.h"
#include "SeqList.h"
#include "../Util/status_bool.h"

char *baseConvert(unsigned long long number, int base) {
    if (base < 2 || base > 62) {
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
        pushLS(ls, number % base);
        number = number / base;
    }
    SeqList seqList = initSeqList(12);
    SeqList *result = &seqList;
    while (!isLStackEmpty(ls)) {
        int raw = popLS(ls);   //number is stored in data(char)
        if (raw >= 0 && raw < 10) {    //convert int to char
            raw += 48; //ASCII 0~9==48~57
        } else if (raw > 10 && raw <= 35) {
            raw += 87; //ASCII a~z==97~122
        } else if (raw > 35 && raw <= 61) {
            raw += 29;  //ASCII A~Z==65~90
        } else {
            return _ERRNULL;
        }
        appendSL(result, raw);    //append converted char into SeqList (similar to char[])
    }
    return toCharArray(result);
}