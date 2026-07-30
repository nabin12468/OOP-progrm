#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0;

    printf("Enter binary string: ");
    scanf("%s", str);

    for(int i=0;i<strlen(str);i++) {

        if(str[i]=='0') {
            switch(state) {
                case 0: state=2; break;
                case 1: state=3; break;
                case 2: state=0; break;
                case 3: state=1; break;
            }
        }

        else if(str[i]=='1') {
            switch(state) {
                case 0: state=1; break;
                case 1: state=0; break;
                case 2: state=3; break;
                case 3: state=2; break;
            }
        }

        else {
            printf("Invalid Input\n");
            return 0;
        }
    }

    if(state==0 || state==2) {
        printf("Accepted\n");
    }
    else {
        printf("Not Accepted\n");
    }
}