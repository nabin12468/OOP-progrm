// binary addition and subtraction

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to add two binary numbers
void binaryAddition(char a[], char b[], char result[]) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0, k = 0;
    
    char temp[100]; // temporary result
    
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        temp[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    
    // Reverse the result
    for(int l = 0; l < k; l++)
        result[l] = temp[k - l - 1];
    result[k] = '\0';
}

// Function to subtract two binary numbers (assumes a >= b)
void binarySubtraction(char a[], char b[], char result[]) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int borrow = 0, k = 0;
    
    char temp[100];
    
    while(i >= 0) {
        int sub = (a[i] - '0') - borrow;
        if(j >= 0) sub -= (b[j--] - '0');
        
        if(sub < 0) {
            sub += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        temp[k++] = sub + '0';
        i--;
    }
    
    // Remove leading zeros and reverse
    while(k > 1 && temp[k-1] == '0') k--;
    
    for(int l = 0; l < k; l++)
        result[l] = temp[k - l - 1];
    result[k] = '\0';
}

int main() {
    char bin1[100], bin2[100], sum[100], diff[100];
    
    printf("Enter first binary number: ");
    scanf("%s", bin1);
    printf("Enter second binary number: ");
    scanf("%s", bin2);
    
    binaryAddition(bin1, bin2, sum);
    binarySubtraction(bin1, bin2, diff); // assumes bin1 >= bin2
    
    printf("Binary Addition: %s + %s = %s\n", bin1, bin2, sum);
    printf("Binary Subtraction: %s - %s = %s\n", bin1, bin2, diff);
    
    return 0;
}