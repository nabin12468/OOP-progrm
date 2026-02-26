#include <stdio.h>

int main() {
    long long binary, temp;
    int remainder;
    long long onesComplement = 0;
    int place = 1;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    temp = binary;

    while (temp != 0) {
        remainder = temp % 10;

        // Flip the bit: 0 -> 1, 1 -> 0
        if (remainder == 0)
            remainder = 1;
        else
            remainder = 0;

        onesComplement = onesComplement + remainder * place;
        place *= 10;
        temp /= 10;
    }

    printf("1's Complement = %lld\n", onesComplement);

    return 0;
}