#include "grains.h"

uint64_t square(uint8_t index) {
    uint64_t result = 1;

    if (index < 1 || 64 < index) {
        result = 0;
    } else {
        for (uint8_t i = 1; i < index; i++)
            result *= 2;
    }

    return result;
}

uint64_t total(void) {
    uint64_t result = 0;

    for (uint8_t i = 1; i < 65; i++)
        result += square(i);

    return result;
}
