#include "DataStructure/BaseConvert.h"
#include <stdio.h>

int main() {
    char* string = baseConvert(10000000000000000000,62);
    printf("%s\n",string);

}
