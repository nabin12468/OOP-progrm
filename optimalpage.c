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

    int frame[f];

    for (int i = 0; i < f; i++)
        frame[i] = -1;

    int faults = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int replace = -1;

            for (int j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    replace = j;
                    break;
                }
            }

            if (replace == -1) {
                int farthest = -1;

                for (int j = 0; j < f; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k])
                            break;
                    }

                    if (k == n) {
                        replace = j;
                        break;
                    }

                    if (k > farthest) {
                        farthest = k;
                        replace = j;
                    }
                }
            }

            frame[replace] = pages[i];
            faults++;
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