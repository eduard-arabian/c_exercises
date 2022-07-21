/**************************************************************************
*  Copyright (c) 2022. Eduard Arabian.                                    *
*                                                                         *
*  Write a C program to check whether the given number is a palindrome    *
*  number or not? (without sign check)                                    *
*                                                                         *
***************************************************************************/

#include "integer.h"
#include <stdlib.h>

int main() {
    char *number = NULL;

    number = getInteger();

    if (number == NULL) {
        fprintf(stderr, "n/a\n");
    } else {
        int index = 0;
        int check = 1;
        int length = getIntegerLength(number);

        while (check && index++ < length / 2)
            if (number[index] != number[length - index - 1])
                check = 0;

        fprintf(stdout, "This is%sa palindrome number\n", check ? " ": " not ");

        free(number);
    }

/*
    if (!fscanf(stdin, "%d", &number) || getchar() != '\n') {
        fprintf(stderr, "n/a\n");
        bye();
    } else {
        int check = 0;
        for (int i = 1; i <= number; i++)
            if (!(number % i) && ++check > 2)
                break;
        printf("This is%sa prime number\n", check > 2 ? " not ": " ");
    }
*/

    return 0;
}
