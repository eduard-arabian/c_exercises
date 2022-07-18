#include "square_root.h"

unsigned int square_root(unsigned int x) {
    unsigned int s = x;

    while (s * s > x)
        s -= 1;

    return s;
}
