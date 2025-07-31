// program to demonstarte the use of function template

#include <iostream>
using namespace std;
template <class t , class u>

t getmin (t a, u b) {
    t result ;
result = (a < b) ? a : b;
return (result);
}

int main() {
    int x=5,r;
    long y=9;
    r= getmin(x,y);
    cout <<"smaller Number between two number is : " << r << endl;
    return 0;
}