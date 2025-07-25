// constructor overloding
// constructor overloading
#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    complex() {
        a = 0;
        b = 0;
    }
    complex(int x, int y) {
        a = x;
        b = y;
    }
    complex(int x) {
        a = x;
        b = 0;
    }
    void printNumber() {
        cout << "Complex number is: " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    complex c1(3, 4); // constructor with two parameters
    c1.printNumber();
    complex c2(5); // constructor with one parameter
    c2.printNumber();
    complex c3; // default constructor
    c3.printNumber();
    return 0;
}