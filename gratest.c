#include "grains.h"
#include <stdio.h>

int main() {
    printf("1 is %ju\n", (uintmax_t)square(1));
    printf("2 is %ju\n", (uintmax_t)square(2));
    printf("3 is %ju\n", (uintmax_t)square(3));
    printf("4 is %ju\n", (uintmax_t)square(4));
    printf("16 is %ju\n", (uintmax_t)square(16));
    printf("32 is %ju\n", (uintmax_t)square(32));
    printf("64 is %ju\n", (uintmax_t)square(64));
    printf("65 is %ju\n", (uintmax_t)square(65));
    printf("0 is %ju\n", (uintmax_t)square(0));
    printf("total is %ju\n", (uintmax_t)total());

    return 0;
}
