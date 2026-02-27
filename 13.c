//1's and 2's complement of a binary number

#include <stdio.h>
#include <string.h>

int main() {
char binary[20], ones[20], twos[20];
int len, carry = 1;

printf("Enter binary number: ");
scanf("%s", binary);

len = strlen(binary);

// 1's complement
for (int i = 0; i < len; i++) {
ones[i] = (binary[i] == '0') ? '1' :'0';
}
ones[len] = '\0';

// 2's complement
for (int i = len - 1; i >= 0; i -- ) {
if (ones[i] == '1' && carry == 1) {
twos[i] = '0';
} else if (ones[i] == '0' && carry == 1) {
twos[i] ='1';
carry = 0;
} else {
twos[i] = ones[i];
}
}
twos[len] = '\0';

printf("1's Complement = %s\n", ones);
printf("2's Complement =%s\n", twos);

return 0;
}