#cfg 

#include <stdio.h>
#include <string.h>

char s[100];
int p = 0;

int F() {
    if(s[p]=='i' && s[p+1]=='d') {
        p += 2;
        return 1;
    }

    if(s[p]=='(') {
        p++;
        if(E() && s[p]==')') {
            p++;
            return 1;
        }
    }
    return 0;
}

int T() {
    if(!F()) return 0;
    while(s[p]=='*') {
        p++;
        if(!F()) return 0;
    }
    return 1;
}

int E() {
    if(!T()) return 0;
    while(s[p]=='+') {
        p++;
        if(!T()) return 0;
    }
    return 1;
}

int main() {
    printf("Enter expression: ");
    scanf("%s", s);

    printf(E() && s[p]=='\0' ? "Accepted" : "Rejected");
    return 0;
}