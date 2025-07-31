// program to overload postfix increment operator

#include <iostream>
using namespace std;
class rectangle{
    int length, breadth;
    public:
    rectangle(int l,int b){
        length = l;
        breadth = b;
    }
    void operator ++(int) { // Postfix increment
        length++;
        breadth++;
    }
    void show(){
        cout <<"overloading the postfix oprerator" << endl;
        cout<<"length = " << length << endl;
        cout<<"breadth = " << breadth << endl;
    }
};

int main() {
    rectangle r1(10, 20);
    r1++;
    r1.show(); // Display the updated values

    return 0;
}