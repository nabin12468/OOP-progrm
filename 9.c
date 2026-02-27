//booth algorithm

#include <stdio.h>
#include <string.h>

#define BITS 8

// Convert decimal to binary array (two's complement)
void decimalToBinary(int n, int bin[]) {
    int num = n < 0 ? -n : n;
    for(int i = BITS-1; i >= 0; i--) {
        bin[i] = num % 2;
        num /= 2;
    }
    if(n < 0) {
        // 2's complement
        for(int i = 0; i < BITS; i++) bin[i] = 1 - bin[i]; // 1's complement
        int carry = 1;
        for(int i = BITS-1; i >= 0; i--) {
            int sum = bin[i] + carry;
            bin[i] = sum % 2;
            carry = sum / 2;
        }
    }
}

// Add two binary arrays
void addBinary(int a[], int b[], int res[]) {
    int carry = 0;
    for(int i = BITS-1; i >= 0; i--) {
        int sum = a[i] + b[i] + carry;
        res[i] = sum % 2;
        carry = sum / 2;
    }
}

// Arithmetic right shift AC-Q-Q1
void rightShift(int AC[], int Q[], int *Q1) {
    int newQ1 = Q[BITS-1];
    for(int i = BITS-1; i > 0; i--) Q[i] = Q[i-1];
    Q[0] = AC[BITS-1];
    for(int i = BITS-1; i > 0; i--) AC[i] = AC[i-1];
    AC[0] = AC[0]; // sign bit remains
    *Q1 = newQ1;
}

// Convert binary array to decimal
int binaryToDecimal(int bin[]) {
    int negative = bin[0];
    int temp[BITS];
    for(int i = 0; i < BITS; i++) temp[i] = bin[i];
    if(negative) {
        // 2's complement
        for(int i = 0; i < BITS; i++) temp[i] = 1 - temp[i];
        int carry = 1;
        for(int i = BITS-1; i >= 0; i--) {
            int sum = temp[i] + carry;
            temp[i] = sum % 2;
            carry = sum / 2;
        }
    }
    int res = 0;
    for(int i = 0; i < BITS; i++) res = res*2 + temp[i];
    return negative ? -res : res;
}

int main() {
    int M_decimal, Q_decimal;
    printf("Enter multiplicand M: ");
    scanf("%d", &M_decimal);
    printf("Enter multiplier Q: ");
    scanf("%d", &Q_decimal);

    int AC[BITS] = {0}, Q[BITS], M[BITS], M_neg[BITS], temp[BITS], Q1 = 0;

    decimalToBinary(M_decimal, M);
    decimalToBinary(Q_decimal, Q);

    memcpy(M_neg, M, sizeof(M));
    // 2's complement of M for subtraction
    for(int i = 0; i < BITS; i++) M_neg[i] = 1 - M_neg[i];
    int carry = 1;
    for(int i = BITS-1; i >= 0; i--) {
        int sum = M_neg[i] + carry;
        M_neg[i] = sum % 2;
        carry = sum / 2;
    }

    // Booth Algorithm
    for(int step = 1; step <= BITS; step++) {
        int Q0 = Q[BITS-1];
        if(Q0 == 0 && Q1 == 1) {
            addBinary(AC, M, temp);
            memcpy(AC, temp, sizeof(temp));
        } else if(Q0 == 1 && Q1 == 0) {
            addBinary(AC, M_neg, temp);
            memcpy(AC, temp, sizeof(temp));
        }
        rightShift(AC, Q, &Q1);
    }

    // Combine AC and Q for final 16-bit product
    int final[2*BITS];
    for(int i = 0; i < BITS; i++) final[i] = AC[i];
    for(int i = 0; i < BITS; i++) final[i+BITS] = Q[i];

    // Convert final 16-bit product to decimal
    int sign = final[0];
    int product = 0;
    int temp16[16];
    for(int i = 0; i < 16; i++) temp16[i] = final[i];
    if(sign) {
        // 2's complement
        for(int i = 0; i < 16; i++) temp16[i] = 1 - temp16[i];
        int carry = 1;
        for(int i = 15; i >= 0; i--) {
            int sum = temp16[i] + carry;
            temp16[i] = sum % 2;
            carry = sum / 2;
        }
    }
    for(int i = 0; i < 16; i++) product = product*2 + temp16[i];
    if(sign) product = -product;

    printf("Decimal product: %d\n", product);
    return 0;
}