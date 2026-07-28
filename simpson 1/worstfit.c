#include <stdio.h>

int main() {
    int nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb];

    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np];

    printf("Enter sizes of processes:\n");
    for (int i = 0; i < np; i++)
        scanf("%d", &process[i]);

    int allocation[np];

    for (int i = 0; i < np; i++)
        allocation[i] = -1;

    // Worst Fit Allocation
    for (int i = 0; i < np; i++) {
        int worst = -1;

        for (int j = 0; j < nb; j++) {
            if (block[j] >= process[i]) {
                if (worst == -1 || block[j] > block[worst]) {
                    worst = j;
                }
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    