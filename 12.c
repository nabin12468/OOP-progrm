// Non-restoring division algorithm in C

#include <stdio.h>

int main() {
    unsigned int dividend, divisor;
    printf("Enter dividend: ");
    scanf("%u", &dividend);
    printf("Enter divisor: ");
    scanf("%u", &divisor);

    unsigned int n = 32; // number of bits for operation
    unsigned int Q = dividend;
    unsigned int M = divisor;
    int AC = 0; // accumulator (can be negative)

    for(int i = 0; i < n; i++) {
        // Left shift [AC,Q] combined
        AC = (AC << 1) | ((Q & (1U << 31)) >> 31);
        Q = Q << 1;

        // Non-restoring step
        if(AC >= 0)
            AC = AC - M;
        else
            AC = AC + M;

        // Set LSB of Q
        if(AC >= 0)
            Q = Q | 1;
        else
            Q = Q & ~1U;
    }

    // Final correction
    if(AC < 0)
        AC = AC + M;

    printf("Quotient = %u\n", Q);
    printf("Remainder = %d\n", AC);

    return 0;
}