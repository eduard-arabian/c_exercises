// Copyright (c) 2022. Eduard Arabian.

#include "isogram.h"
#include <stdio.h>

int main() {
    printf("\"\" is %d\n", is_isogram(""));
    printf("NULL is %d\n", is_isogram(NULL));
    printf("isogram is %d\n", is_isogram("isogram"));
    printf("eleven is %d\n", is_isogram("eleven"));
    printf("zzyzx is %d\n", is_isogram("zzyzx"));
    printf("subdermatoglyphic is %d\n", is_isogram("subdermatoglyphic"));
    printf("Alphabet is %d\n", is_isogram("Alphabet"));
    printf("alphAbet is %d\n", is_isogram("alphAbet"));
    printf("thumbscrew-japingly is %d\n", is_isogram("thumbscrew-japingly"));
    printf("thumbscrew-jappingly is %d\n", is_isogram("thumbscrew-jappingly"));
    printf("six-year-old is %d\n", is_isogram("six-year-old"));
    printf("Emily Jung Schwartzkopf is %d\n", is_isogram("Emily Jung Schwartzkopf"));
    printf("accentor is %d\n", is_isogram("accentor"));
    printf("angola is %d\n", is_isogram("angola"));
    printf("up-to-date is %d\n", is_isogram("up-to-date"));

    return 0;
}
