// program to demonstrate the use of exception handling.

#include <iostream>
using namespace std;

int main() {
    int a,b;
cout << "Enter values of a and b:\n";
cin >> a >> b;
    try {
        if (b == 0)
            throw b;
        else
            cout << "result = " << (float)a / b << endl;
    } catch (int i) {
        cout << "Divide by zero exception: b = " << i << endl;

    }
    cout << "END";
    return 0;
}