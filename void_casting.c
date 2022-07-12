// Copyright (c) 2022. Eduard Arabian.

#include <stdio.h>

int main() {
    int b = 65;
    void *p = &b;
    int *j = (int*)p;
    char *c = (char*)p;

    printf("%d %c\n", *j, *c);

    return 0;
}
