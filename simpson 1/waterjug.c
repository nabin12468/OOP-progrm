#include <stdio.h>

void pour(int *a, int *b, int cap) {
    int x = cap - *b;

    if(*a <= x) {
        *b += *a;
        *a = 0;
    } else {
        *a -= x;
        *b = cap;
    }
}

int main() {
    int a = 0, b = 0;

    printf("Initial: (%d, %d)\n", a, b);

    b = 3;
    printf("Fill 3L: (%d, %d)\n", a, b);

    pour(&b, &a, 4);
    printf("Pour 3L into 4L: (%d, %d)\n", a, b);

    b = 3;
    printf("Fill 3L: (%d, %d)\n", a, b);

    pour(&b, &a, 4);
    printf("Pour into 4L: (%d, %d)\n", a, b);

    return 0;
}