//friend function
#include <iostream>
using namespace std;

// Forward declaration of class Calculator
class Complex;
class Calculator { // Fixed class name to uppercase
public:
    int add(int a, int b) {
        return (a + b);
    }

    int sumRealComplex(Complex o1, Complex o2); // Declaration of friend function
};

class Complex {
    int a, b;
    friend int Calculator::sumRealComplex(Complex, Complex);

public:
    void setNumber(int n1, int n2) {
        a = n1;
        b = n2;
    }

    void printNumber() {
        cout << "Complex number: " << a << " + " << b << "i" << endl;
    }
};

int Calculator::sumRealComplex(Complex o1, Complex o2) {
    return (o1.a + o2.a);
}

int main() {
    Complex c1, c2;
    c1.setNumber(1, 4);
    c2.setNumber(5, 7);

    Calculator calc;
    int sum = calc.sumRealComplex(c1, c2);

    cout << "Sum of real parts: " << sum << endl;

    return 0;
}

// one class function can be a friend of another class function