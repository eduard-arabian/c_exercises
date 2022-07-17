#include <stdio.h>
#include "isogram.h"

bool is_isogram(const char phrase[]) {
    int i = 0;
    bool result;

    if (phrase == NULL) {
        result = false;
    } else {
        result = true;
        int alpha[26] = { 0 };
        while (phrase[i] != '\0') {
            if (phrase == NULL) {
                result = false;
                break;
            } else if ('a' <= phrase[i] && phrase[i] <= 'z') {
                if (++alpha[phrase[i] - 97] > 1) {
                    result = false;
                    break;
                }
            } else if ('A' <= phrase[i] && phrase[i] <= 'Z') {
                if (++alpha[phrase[i] - 65] > 1) {
                    result = false;
                    break;
                }
            } else if (phrase[i] == ' ' || phrase[i] == '-') {
                i++;
                continue;
            } else {
                result = false;
                break;
            }
            i++;
        }
    }

    return result;
}
