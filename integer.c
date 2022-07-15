// Copyright (c) 2022. Eduard Arabian.

#include "integer.h"

void bye() {
    exit(1);
}

char* getInteger() {
    char value;
    int counter = 1;
    char *result = NULL;

    fscanf(stdin, "%c", &value) == 1 && (('0' <= value && value <= '9')
        || value == '-' || value == '+') && value != '\n' ?
        result = buffer_up(&counter, result, value) : bye();

    while (fscanf(stdin, "%c", &value) == 1 && value != '\n') {
        if (value < '0' || '9' < value) {
            if (result != NULL)
                free(result);
            bye();
        } else {
            result = buffer_up(&counter, result, value);
        }
    }

    if (counter == 2 && (result[0] == '-' || result[0] == '+')) {
        free(result);
        result = NULL;
    } else {
        result[counter - 1] = '\0';
    }

    return result;
}

char* buffer_up(int* counter, char* result, char value) {
    *counter += 1;
    result = realloc(result, *counter * sizeof(char));
    result[*counter - 2] = value;

    return result;
}
