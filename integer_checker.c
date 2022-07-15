// Copyright (c) 2022. Eduard Arabian.

#include "integer.h"

int main() {
    char *result;

    printf("Enter integer number: ");
    result = getInteger();
    if (result != NULL) {
        fprintf(stdout, "You entered: %s\n", result);
        free(result);
    } else {
        fprintf(stderr, "That's not an integer\n");
        bye();
    }

    return 0;
}
