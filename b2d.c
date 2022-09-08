#include <stdio.h>
#include <math.h>

long long convertBinaryToDecimal(long long bin);

int main(){
    long long bin;
    long long decimal;

    printf("Input binary number: ");
    scanf("%lld", &bin);
    decimal = convertBinaryToDecimal(bin);
    if(decimal < 0)
        printf("That's not a binary.\n");
    else
        printf("%lld\n", decimal);
    return 0;
}

long long convertBinaryToDecimal(long long bin) {
    int digit;
    long long bi = bin / 10;
    long long decimal = 0;
    int sign = 0;

    if(bin < 0)
        decimal = -1;
    else {
        for(; bin > 0; sign++){
            bi = bin / 10;
            digit = bin - bi * 10;
            bin = bi;
            if(digit == 1)
                decimal += pow(2, sign);
            else if (0 > digit || digit > 1) {
                decimal = -1;
                bin = 0;
            }
        }
    }

    return decimal;
}

