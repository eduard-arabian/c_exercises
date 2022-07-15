/**************************************************************************
*  Copyright (c) 2022. Eduard Arabian.                                    *
*                                                                         *
*  Write a C program to check whether the given number is a prime number  *
*  or not?                                                                *
*                                                                         *
***************************************************************************/

#include "integer.h"

int main() {
    int number;

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

    return 0;
}
