//call by pointer 
//pass by address

#include <iostream>
using namespace std;

void passbyvalue(int*x, int*y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 10, b = 20;
    cout << "Before swapping: a = " << a << ", b = " << b
        << endl;
        passbyvalue(&a, &b);
    cout << "After swapping: a = " << a << ", b = " << b
        << endl;
    
    return 0;
}