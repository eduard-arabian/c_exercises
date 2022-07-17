// Copyright (c) 2022. Eduard Arabian.

#include <stdbool.h>
#include <stdio.h>

bool is_armstrong_number(int candidate);

int main() {
    int number;

    scanf("%d", &number);
    printf("%d", is_armstrong_number(number));

    return 0;
}

bool is_armstrong_number(int candidate) {
    int armstrong = candidate;
    int check = candidate;
    int length = !armstrong;

    while (armstrong) {
        length++;
        armstrong /= 10;
    }

    for (int i = length; i > 0; i--) {
        int digit = check % 10;
        int power = 1;
        check /= 10;
        for (int j = length; j > 0; j--)
            power *= digit;
        armstrong += power;
    }

    return (candidate == armstrong);
}
