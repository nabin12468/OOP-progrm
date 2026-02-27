//booth algorithm

#include <stdio.h>

// Function to display bits clearly
void printBinary(int n, int bits) {
for (int i = bits - 1; i >= 0; i -- ) {
printf("%d", (n >> i) & 1);
}
}
int main() {
int M, Q;
printf("Enter Multiplicand (M): ");
scanf("%d", &M);
printf("Enter MultipLier (Q): ");
scanf("%d", &Q);

// Use 8-bit logic for the simulation
int A = 0;
int Q_minus_1 = 0;
int m_reg = M & 0xFF;
int q_reg = Q & 0xFF;
int count = 8;

printf("\n[Initial State]: A="); printBinary(A, 8);
printf(" Q="); printBinary(q_reg, 8);
printf(" Q-1=%d\n", Q_minus_1);
printf(" ---------------------------\n");

for (int i = 0; i < count; i++) {
int QQ = q_reg & 1;

// 1. Comparison & Operation
if (QQ == 1 && Q_minus_1 == 0) {
A = (A - m_reg) & 0xFF; // Subtraction
} else if (QQ == 0 && Q_minus_1 == 1) {
A = (A + m_reg) & 0xFF; // Addition
}

// 2. Arithmetic Right Shift (ASR)
// We treat A and Q as one 16-bit register [A][Q]
int last_bit_A = A & 1;
int sign_bit_A = A & 0x80; // Save the sign bit to preserve it

Q_minus_1 = q_reg & 1;
q_reg = (q_reg >>1) | (last_bit_A << 7);
q_reg &= 0xFF; // Keep it 8-bit

A = (A >> 1) | sign_bit_A; // Shift A but keep its original sign bit
A &= 0xFF; // Keep it 8-bit

printf("Step %d: A=", i+ 1); printBinary(A, 8);
printf(" Q="); printBinary(q_reg, 8);
printf(" Q-1=%d\n", Q_minus_1);
}
// 3. Final Result Assembly
// Combine A (High byte) and Q (Low byte)
int final_res = (A << 8) | q_reg;

// To print the correct negative decimal, we sign-extend to 32-bit
int decimal_output = final_res;
if (final_res & 0x8000) { // If the 16th bit is 1, it's negative
decimal_output |= 0xFFFF0000;
}
printf(" ---------------------------\n");
printf("FINAL BINARY OUTPUT: "); printBinary(final_res, 16);
printf("\nFINAL DECIMAL OUTPUT: %d\n", decimal_output);

return 0;
}