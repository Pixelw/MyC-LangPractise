//
// Created by carl- on 2020/2/14.
//


#include <stdlib.h>
#include <stdio.h>

int sc_nextInt24() {
    //max 24 chars
    char *input = (char *)malloc(sizeof(char)*24);
    char *ptr;
    fgets(input, 24, stdin);
    return strtol(input, &ptr, 10);
}

int sc_nextInt(){
    int i;
    scanf("%d",&i);
    return i;
}

char sc_nextChar() {
    return 0;
}

char *sc_nextString() {
    char *input = (char *)malloc(sizeof(char)*128);
    fgets(input, 128, stdin);
    return input;
}
