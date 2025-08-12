//exception handlinggit



#include <iostream>
using namespace std;

class customer{

};

int main() {
    int a,b;
    cin>>a>>b;

    try{
        if(b==0)
        throw "divided by zero is not possible";
    int c=a/b;
    cout<<c<<endl;
    }
    catch(const char *e)
    {
        cout<<"exception occured:"<<e<<endl;
    }
    return 0;
}