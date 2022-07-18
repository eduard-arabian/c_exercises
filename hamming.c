#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    int result = 0;

    while (*lhs != '\0' && *rhs != '\0') {
        if (*lhs != *rhs)
            result++;
        lhs++;
        rhs++;
    }

    if (*lhs != *rhs && (*lhs == '\0' || *rhs == '\0'))
        result = -1;

    return result;
}
