//2's complement substraction

#include <stdio.h>
#include <string.h>

// Function to find 1's complement
void onesComplement(char str[], char result[]) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        result[i] = (str[i] == '0') ? '1' : '0';
    }
    result[len] = '\0';
}

// Function to add 1 to a binary number (for 2's complement)
void addOne(char str[], char result[]) {
    int len = strlen(str);
    int carry = 1; // Adding 1
    for(int i = len - 1; i >= 0; i--) {
        int bit = str[i] - '0';
        int sum = bit + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[len] = '\0';
}

// Function to add two binary numbers
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
    result[len] = '\0';
}

int main() {
    char A[20], B[20];
    char B_ones[20], B_twos[20], result[20];

    printf("Enter binary number A: ");
    scanf("%s", A);
    printf("Enter binary number B: ");
    scanf("%s", B);

    // Step 1: 1's complement of B
    onesComplement(B, B_ones);

    // Step 2: 2's complement of B
    addOne(B_ones, B_twos);

    // Step 3: Add A and 2's complement of B
    addBinary(A, B_twos, result);

    printf("Result of A - B in 2's complement: %s\n", result);
    return 0;
}