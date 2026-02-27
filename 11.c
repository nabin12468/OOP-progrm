//Program for Restoring Division algorithm

#include <stdio.h>
#define BITS 8

int main() {
    unsigned int dividend, divisor;
    printf("Enter dividend: ");
    scanf("%u", &dividend);
    printf("Enter divisor: ");
    scanf("%u", &divisor);

    unsigned int A = 0; // Accumulator
    unsigned int Q = dividend;
    unsigned int M = divisor;

    for(int i = 0; i < BITS; i++) {
        // Left shift [A,Q] combined
        A = ((A << 1) | ((Q & 0x80) >> 7)) & 0xFF; // Keep 8 bits
        Q = (Q << 1) & 0xFF;                        // Keep 8 bits

        // Subtract M from A
        int temp = (int)A - (int)M; // Use int for signed subtraction
        if(temp < 0) {
            Q = Q & ~1;    // Set LSB of Q to 0
            // Restore A
        } else {
            A = (unsigned int)temp; // Update A
            Q = Q | 1;     // Set LSB of Q to 1
        }
    }

    printf("Quotient = %u\n", Q);
    printf("Remainder = %u\n", A);

    return 0;
}