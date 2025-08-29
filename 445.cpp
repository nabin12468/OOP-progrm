#include <iostream>
using namespace std;

class rectangle {
    int l, b;
public:
    rectangle(int x, int y) {
        l = x;
        b = y;
    }
    friend int area(rectangle r); // Friend function declaration
};

int area(rectangle r) { // Friend function definition
    return r.l * r.b;
}

int main() {
    rectangle r(10, 5);
    cout << "Area is " << area(r);
    return 0;
}