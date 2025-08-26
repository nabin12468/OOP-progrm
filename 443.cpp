//function templalte


#include <iostream>
using namespace std;

template <class T1,class T2>
float funcAVerage(T1 a, T2 b){
    float avg = (a+b)/2.0;
    return avg;
}


int main() {
    float a;
    a = funcAVerage(5,6.5);
    cout<<"Average of 5 and 6.5 is "<<a<<endl;
    
    return 0;
}