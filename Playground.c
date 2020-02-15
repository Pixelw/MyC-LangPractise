#include "DataStructure/BaseConvert.h"
#include <stdio.h>

int main() {
    char* string = baseConvert(42949672888800,16);
    printf("%s\n",string);
}
