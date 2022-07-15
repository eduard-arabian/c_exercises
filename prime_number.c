/* Copyright (c) 2022. Eduard Arabian.
*  Write a C program to check whether the given number is a prime number
*  or not?
*/

#include <stdio.h>
#include <stdlib.h>

void bye();

int main() {
    int number;

    if (!fscanf(stdin, "%d", &number) || getchar() != '\n') {
        bye();
    } else {
        register int check = 0;
        for (register int i = 1; i <= number; i++)
            if (!(number % i) && ++check > 2)
                break;
        printf("This is%sa prime number\n", check > 2 ? " not ": " ");
    }

    return 0;
}

void bye() {
    fprintf(stderr, "n/a\n");
    exit(1);
}
