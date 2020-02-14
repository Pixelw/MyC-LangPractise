#include "Util/scanner.h"
#include "DataStructure/LinkedStack.h"
#include <stdio.h>

int main() {

    LinkedStack s = initLStack();
    LinkedStack *ls = &s;
    pushLS(ls,'1');
    pushLS(ls,'2');
    pushLS(ls,'3');
    pushLS(ls,'4');
    pushLS(ls,'5');
    pushLS(ls,'1');
    pushLS(ls,'2');
    pushLS(ls,'3');
    pushLS(ls,'4');
    pushLS(ls,'5');
    pushLS(ls,'a');
    pushLS(ls,'b');
    showLStack(ls);

    popLS(ls);popLS(ls);popLS(ls);
    showLStack(ls);
    DestroyLStack(ls);
//
//    char *string = sc_nextString();
//    printf("%s", string);
}
