// program to show the concept of reference variable


#include <iostream>
using namespace std;

int main() {
    int a=20;
    int &b=a;
    cout<<a<<""<<b<<endl;
    ++b;
    cout<<a<<""<<b<<endl;
    return 0;
}

