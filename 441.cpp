//ambiguity
#include <iostream>
using namespace std;

class A{
    public:
    void show(){
    cout<< "Hello A" << endl;
    }
};
class B{
    public:
    void show (){
        cout<< "Hello B" << endl;

    }
};
class c :public A, public B {
    public:
    void show() {
        A :: show();
    }
    };

int main() {
    A aobj;
    B bobj;
    aobj.show();
    bobj.show();
    c c;
    c.show(); // Calls A's show method due to the implementation in class c

    return 0;
}