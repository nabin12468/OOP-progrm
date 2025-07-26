// #constructors and destructors
//constructor is a special member function with same name as of the class.it is used to initialize the objects of the class.
//it is automatically invoked whenever an object is created.(invoked means call or execute)
#include <iostream>
using namespace std;

class Complex {
    int a, b;
    public:
    //creating a constructor
    Complex(void);//constructor declaration
    void printData() {
        cout << "your number  is: " << a << "+" << b << "i"<< endl;
       
    }
};

Complex :: Complex(void)//-----> this is a default constructor as it takes no parameters

{
    a = 10;
    b = 20;
    cout << "Constructor called" << endl;  // here we are defining the constructor

}
int main() {
    Complex c1,c2,c3;
    c1.printData();
    c2.printData();
    c3.printData();
    
    return 0;
}

/* characteristics  of constructor:
 
1.it should be declared in the public section of the class
2.they are automMatically invoked whenever an object is created
3. do cannot return values and do not have return types
4.it can have default arguments
5. we cannot refer to their address */