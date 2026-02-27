// shift add multiplication

#include <stdio.h>

// Helper to print bits clearly
void printBits(int value, int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
}

int main() {
    unsigned int M, Q, A = 0, count;
    int n = 4; // 4-bit multiplication

    printf("Enter Multiplicand M (0-15): ");
    scanf("%u", &M);
    printf("Enter Multiplier Q (0-15): ");
    scanf("%u", &Q);

    count = n;
    printf("\nCycle |   A   |   Q   | Action\n");
    printf("--------------------------------\n");
    printf("Init  | "); printBits(A, n); printf("  | "); printBits(Q, n); printf("  | -\n");

    while (count > 0) {
        // Step 1: Check LSB of Q
        if (Q & 1) {
            A = A + M;
            printf("Add   | "); printBits(A, n); printf("  | "); printBits(Q, n); printf("  | A = A + M\n");
        }

        // Step 2: Shift Right (Logical)
        // Treat A and Q as a single 8-bit register for the shift
        unsigned int combined = (A << n) | Q;
        combined >>= 1;
        
        // Extract shifted A and Q back
        A = (combined >> n) & 0xF; // Masking to keep it 4-bit
        Q = combined & 0xF;

        printf("Shift | "); printBits(A, n); printf("  | "); printBits(Q, n); printf("  | Shift Right\n");
        count--;
    }

    printf("--------------------------------\n");
    printf("Final Product: %u (Binary: ", (A << n) | Q);
    printBits((A << n) | Q, 8);
    printf(")\n");

    return 0;
}