#include <stdlib.h>
#include <stdio.h>

int *my_malloc(size_t s);

void my_free(void *ptr);

size_t allocated_size(void *ptr);

int main() {
    int *array = my_malloc(sizeof(int) * 3);

    printf("%u\n", (unsigned int)allocated_size(array));
    my_free(array);

    return 0;
}

int *my_malloc(size_t s) {
    size_t *ret = malloc(sizeof(size_t) + s);

    *ret = s;

    return (int*)(ret + 1);
}

void my_free(void *ptr)  {
    free((size_t*)ptr - 1);
}

size_t allocated_size(void *ptr) {
    return ((size_t*)ptr)[-1];
}
