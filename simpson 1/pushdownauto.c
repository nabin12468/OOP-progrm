#include <stdio.h>

char st[100];
int top = -1;

int main() {
    char s[100];
    int i, state = 0;

    printf("Enter string: ");
    scanf("%s", s);

    for(i=0; s[i]; i++) {
        if(state == 0 && s[i] == 'a')
            st[++top] = 'A';

        else if(s[i] == 'b' && top >= 0) {
            top--;
            state = 1;
        }

        else {
            printf("Rejected");
            return 0;
        }
    }

    printf(state == 1 && top == -1 ? "Accepted" : "Rejected");
    return 0;
}