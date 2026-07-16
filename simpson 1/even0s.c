#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0; // q0 = even 0s, q1 = odd 0s

    printf("Enter binary string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0')
            state = 1 - state;
        else if (str[i] != '1') {
            printf("Invalid Input\n");
            return 0;
        }
    }

    if (state == 0)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}