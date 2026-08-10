#include <stdio.h>

int main() {
    int A, B;

    printf("Enter A and B (0 or 1): ");
    scanf("%d %d", &A, &B);

    printf("AND = %d\n", A && B);
    printf("OR  = %d\n", A || B);
    printf("NOT A = %d\n", !A);
    printf("NOT B = %d\n", !B);

    return 0;
}