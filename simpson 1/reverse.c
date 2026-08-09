#include <stdio.h>
#include <string.h>

char st[100];
int top = -1;

int main() {
    char s[100];
    int i, n;

    printf("Enter string: ");
    scanf("%s", s);

    n = strlen(s);

    if(n % 2 != 0) {
        printf("Rejected");
        return 0;
    }

    for(i=0; i<n/2; i++)
        st[++top] = s[i];

    for(i=n/2; i<n; i++)
        if(top < 0 || st[top--] != s[i]) {
            printf("Rejected");
            return 0;
        }

    printf(top == -1 ? "Accepted" : "Rejected");
    return 0;
}