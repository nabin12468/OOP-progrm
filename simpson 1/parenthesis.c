#include <stdio.h>
#include <string.h>

char s[100], st[100];
int top = -1;

int main() {
    int i;
    printf("Enter string: ");
    scanf("%s", s);

    for(i = 0; s[i]; i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st[++top] = s[i];

        else if(s[i]==')' || s[i]=='}' || s[i]==']') {
            if(top == -1 ||
              (s[i]==')' && st[top]!='(') ||
              (s[i]=='}' && st[top]!='{') ||
              (s[i]==']' && st[top]!='[')) {
                printf("Rejected");
                return 0;
            }
            top--;
        }
    }

    printf(top == -1 ? "Accepted" : "Rejected");
    return 0;
}