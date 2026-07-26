#include <stdio.h>

int main() {
    int nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb];

    printf("Enter block sizes:\n");
    for(int i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np];

    printf("Enter process sizes:\n");
    for(int i = 0; i < np; i++)
        scanf("%d", &process[i]);

    int allocation[np];

    for(int i = 0; i < np; i++)
        allocation[i] = -1;

    for(int i = 0; i < np; i++) {
        int best = -1;

        for(int j = 0; j < nb; j++) {
            if(block[j] >= process[i]) {
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if(best != -1) {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");

    for(int i = 0; i < np; i++) {
        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}