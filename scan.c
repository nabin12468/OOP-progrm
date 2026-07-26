#include <stdio.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, head, disk_size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    sort(req, n);

    int total = 0;
    int pos = head;
    int index = 0;

    while(index < n && req[index] < head)
        index++;

    printf("\nSeek Sequence:\n");

    // Move towards higher tracks
    for(int i = index; i < n; i++) {
        printf("%d ", req[i]);
        total += (req[i] > pos) ? req[i] - pos : pos - req[i];
        pos = req[i];
    }

    if(pos != disk_size - 1) {
        total += (disk_size - 1 - pos);
        pos = disk_size - 1;
    }

    // Reverse direction
    for(int i = index - 1; i >= 0; i--) {
        printf("%d ", req[i]);
        total += (pos > req[i]) ? pos - req[i] : req[i] - pos;
        pos = req[i];
    }

    printf("\n\nTotal Seek Time = %d\n", total);

    return 0;
}