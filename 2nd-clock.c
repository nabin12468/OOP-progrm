#include <stdio.h>

int main() {
    int n, f;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frame[f], ref[f];

    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        ref[i] = 0;
    }

    int pointer = 0;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if page already exists
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                ref[j] = 1;
                found = 1;
                break;
            }
        }

        // Page fault
        if (!found) {
            while (1) {
                if (ref[pointer] == 0) {
                    frame[pointer] = pages[i];
                    ref[pointer] = 1;
                    pointer = (pointer + 1) % f;
                    faults++;
                    break;
                } else {
                    ref[pointer] = 0;
                    pointer = (pointer + 1) % f;
                }
            }
        }

        printf("Frame: ");
        for (int j = 0; j < f; j++) {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}