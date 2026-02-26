//write a program to binary addition

#include <stdio.h>

int main() {    long long binary1, binary2;
    int i = 0, carry = 0;
    int sum[64]; // To store binary sum

    printf("Enter first binary number: ");
    scanf("%lld", &binary1);

    printf("Enter second binary number: ");
    scanf("%lld", &binary2);

    // Perform binary addition
    while (binary1 != 0 || binary2 != 0) {
        sum[i++] = (binary1 % 10 + binary2 % 10 + carry) % 2;
        carry = (binary1 % 10 + binary2 % 10 + carry) / 2;
        binary1 /= 10;
        binary2 /= 10;
    }

    if (carry != 0)
        sum[i++] = carry;

    // Print result in reverse order
    printf("Sum = ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", sum[j]);
    printf("\n");

    return 0;
}