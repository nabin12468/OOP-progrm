//1's complement substraction

#include <stdio.h>
#include <string.h>

void onesComplement(char str[], char result[]) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        result[i] = (str[i] == '0') ? '1' : '0';
    }
    result[len] = '\0';
}

void addBinary(char a[], char b[], char result[]) {
    int len = strlen(a);
    int carry = 0;
    for(int i = len - 1; i >= 0; i--) {
        int bitA = a[i] - '0';
        int bitB = b[i] - '0';
        int sum = bitA + bitB + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }
    // Handle end-around carry
    if(carry) {
        for(int i = len - 1; i >= 0; i--) {
            int bit = result[i] - '0';
            int sum = bit + carry;
            result[i] = (sum % 2) + '0';
            carry = sum / 2;
        }
    }
    result[len] = '\0';
}

int main() {
    char A[20], B[20], B_comp[20], result[20];

    printf("Enter binary number A: ");
    scanf("%s", A);
    printf("Enter binary number B: ");
    scanf("%s", B);

    // Step 1: Get 1's complement of B
    onesComplement(B, B_comp);

    // Step 2: Add A and 1's complement of B
    addBinary(A, B_comp, result);

    printf("Result of A - B in 1's complement: %s\n", result);
    return 0;
}