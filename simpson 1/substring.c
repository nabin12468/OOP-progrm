#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0;

    printf("Enter string: ");
    scanf("%s", str);

    for(int i=0;i<strlen(str);i++) {

        switch(state) {

            case 0:
                if(str[i]=='a')
                    state=0;
                else if(str[i]=='b')
                    state=1;
                else {
                    printf("Invalid Input\n");
                    return 0;
                }
                break;

            case 1:
                if(str[i]=='a')
                    state=0;
                else if(str[i]=='b')
                    state=2;
                else {
                    printf("Invalid Input\n");
                    return 0;
                }
                break;

            case 2:
                state=2;
                break;
        }
    }

    if(state!=2)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}