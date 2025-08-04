// overloading function with different number of arguments
//this is important cpncept
#include <iostream>
using namespace std;

int area(int l,int b)
{
    return l+b;

}
int area (int l)
{
    return l*l;
}
int main() {
    int Sa,ra,l,b;
    cout<<"enter length and breath of rectangle "<<endl;
    cin>>l>>b;
    ra=area(l,b);
    cout<<"area of rectangle="<<ra<<endl;
    cout<<"area of square ="<<Sa<<endl;
    
    return 0;
}