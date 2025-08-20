//operator overloading 
//overload + operator

#include <iostream>
using namespace std;
class demo
{
    int a;
public:
    void getdata(){
        cout << "Enter a number: ";
        cin >> a;
    }
    void putdata(){
        cout << "The number is: " << a << endl;
    }
};

int main() {
    
    return 0;
}