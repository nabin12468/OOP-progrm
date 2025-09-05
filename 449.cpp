#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Operator Overloading for +
    Complex operator+(const Complex& other) {
        // Create a new Complex object to hold the result
        Complex result;
        // Add the real parts and imaginary parts separately
        result.real = real + other.real;
        result.imag = imag + other.imag;
        // Return the new object
        return result;
    }

    // Function to display the complex number
    void display() {
        if (imag >= 0) {
            std::cout << real << " + " << imag << "i" << std::endl;
        } else {
            std::cout << real << " - " << -imag << "i" << std::endl;
        }
    }
};

int main() {
    // Create two Complex number objects
    Complex c1(10.5, 5.2);
    Complex c2(3.1, 2.7);

    // Use the overloaded '+' operator to add the two objects
    Complex sum = c1 + c2;

    // Display the results
    std::cout << "Complex Number 1: ";
    c1.display();
    std::cout << "Complex Number 2: ";
    c2.display();
    std::cout << "Sum: ";
    sum.display();

    return 0;
}