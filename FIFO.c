#include <stdio.h>

int main() {
    int pages, frames;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page[pages];

    printf("Enter page reference string:\n");
    for (int i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[frames];

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    int faults = 0, index = 0;

    for (int i = 0; i < pages; i++) {
        int found = 0;

        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frame[index] = page[i];
            index = (index + 1) % frames;
            faults++;
        }

        printf("Frame: ");
        for (int j = 0; j < frames; j++) {
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