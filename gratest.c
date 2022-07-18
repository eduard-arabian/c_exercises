#include "grains.h"
#include <stdio.h>

int main() {
    printf("1 is %ju\n", square(1));
    printf("2 is %ju\n", square(2));
    printf("3 is %ju\n", square(3));
    printf("4 is %ju\n", square(4));
    printf("16 is %ju\n", square(16));
    printf("32 is %ju\n", square(32));
    printf("64 is %ju\n", square(64));
    printf("65 is %ju\n", square(65));
    printf("0 is %ju\n", square(0));
    printf("total is %ju\n", total());

    return 0;
}
