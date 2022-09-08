#include <stdio.h>
#include <math.h>

long long convertBinaryToDecimal(long long bin);
long long convertDecimalToBinary(int dec);

int main(){
    long long bin;
    long long decimal;
    int dec;

    printf("Input binary number: ");
    scanf("%lld", &bin);
    decimal = convertBinaryToDecimal(bin);
    if(decimal < 0)
        printf("That's not a binary or number is too long.\n");
    else
        printf("%lld\n", decimal);

    printf("Input decimal number: ");
    scanf("%d", &dec);
    decimal = convertDecimalToBinary(dec);
    printf("%lld\n", decimal);

    return 0;
}

long long convertBinaryToDecimal(long long bin){
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

long long convertDecimalToBinary(int dec){
    long long bin = 0;
    int digit;
    long long pos = 1;

    for(; dec > 0;){
        digit = dec % 2;
        dec /= 2;
        bin += digit * pos;
        pos *= 10;
    }

    return bin;
}

