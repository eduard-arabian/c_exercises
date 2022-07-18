#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number) {
   unsigned int result = 0;

    for (unsigned int i = 1; i <= number; i++) {
        result += i * i;
    }

//    return number * (number + 1) * (2 * number + 1) / 6;
    return result;
}

unsigned int square_of_sum(unsigned int number) {
    unsigned int result = 0;

    for (unsigned int i = 1; i <= number; i++) {
        result += i;
    }

//    result = n * (n + 1) >> 1;
    return (result * result);
}

unsigned int difference_of_squares(unsigned int number) {
    return (square_of_sum(number) - sum_of_squares(number));
}
