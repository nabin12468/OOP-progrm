#include <stdio.h>

int main() {
    int monkey = 0, box = 0, banana = 1;

    printf("Monkey is on the floor.\n");

    if(monkey != box) {
        printf("Monkey moves to the box.\n");
        monkey = box;
    }

    printf("Monkey pushes the box below the banana.\n");
    box = banana;

    printf("Monkey climbs on the box.\n");
    printf("Monkey gets the banana.\n");

    return 0;
}