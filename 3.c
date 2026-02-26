#include <stdio.h>

int main() {
    long long binary, temp;
    int remainder;
    long long onesComplement = 0;
    long long twosComplement = 0;
    int place = 1;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    temp = binary;

    // Step 1: Find 1's Complement
    while (temp != 0) {
        remainder = temp % 10;
        remainder = (remainder == 0) ? 1 : 0; // Flip bit
        onesComplement = onesComplement + remainder * place;
        place *= 10;
        temp /= 10;
    }

    // Step 2: Add 1 to 1's Complement to get 2's Complement
    twosComplement = onesComplement + 1;

    printf("2's Complement = %lld\n", twosComplement);

    return 0;
}