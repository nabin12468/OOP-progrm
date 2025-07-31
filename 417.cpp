//program to swap two integer using call by reference

#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main() {
    int num1,num2;
    cout<<"enter first and second number: ";
    cin>>num1>>num2;
    cout<<"before swapping: "<<endl;
    cout<<"num1="<<num1<<"num2="<<num2<<endl;
    swap(num1, num2);
    cout<<"after swapping: "<<endl;
    cout<<"num1="<<num1<<"num2="<<num2<<endl;
    return 0;

}
