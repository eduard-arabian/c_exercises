#include "hamming.h"
#include <stdio.h>

int main() {
    printf("\"\", \"\" is %d\n", compute("", ""));
    printf("A, A is %d\n", compute("A", "A"));
    printf("G, T is %d\n", compute("G", "T"));
    printf("GGACTGAAATCTG, GGACTGAAATCTG is %d\n", compute("GGACTGAAATCTG", "GGACTGAAATCTG"));
    printf("GGACGGATTCTG, AGGACGGATTCT is %d\n", compute("GGACGGATTCTG", "AGGACGGATTCT"));
    printf("AATG, AAA is %d\n", compute("AATG", "AAA"));
    printf("ATA, AGTG is %d\n", compute("ATA", "AGTG"));
    printf("\"\", G is %d\n", compute("", "G"));
    printf("G, \"\" is %d\n", compute("G", ""));

    return 0;
}
