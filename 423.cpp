// C++ program to check if the number is even
// or odd using modulo operator
#include <iostream>
using  namespace std;
int main() {
    int n = 12;

    // If n is completely divisible by 2
    if (n % 2 == 0)
        cout << "Even";

    // If n is NOT completely divisible by 2
    else
        cout << "Odd";
    return 0;
}