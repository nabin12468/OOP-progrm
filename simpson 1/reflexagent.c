#include <stdio.h>

int main() {
    char location, status;

    printf("Enter location (A/B): ");
    scanf(" %c", &location);

    printf("Enter status (D=Dirty, C=Clean): ");
    scanf(" %c", &status);

    if(status == 'D')
        printf("Action: Suck\n");
    else if(location == 'A')
        printf("Action: Move Right\n");
    else
        printf("Action: Move Left\n");

    return 0;
}