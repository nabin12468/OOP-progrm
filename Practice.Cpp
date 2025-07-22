#include <iostream>
using namespace std;

int sum(int a, int b) {
    int c= a + b;
    return c;
}
//call by reference using pointers
void swapPointer(int* a,int* b){ //temp a b
                       // 4   4   5
                        //4   5   5
                        //4   5   4


int temp=*a;
*a=*b;
*b=temp;
}
int main() {
    int a=4,b=5;
   // cout<<"the sum of 4 and 5is: "<<sum(4,5)<<endl;
   cout<<"the value of a is "<<a<<"and the value of b is  "<<b<<endl;
swapPointer(&a,&b);
    cout<<"the value of a is "<<a<<"and the value of b is  "<<b<<endl;
    return 0;
}