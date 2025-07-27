// destruction of objects in C++
//Destructor never takes an argument and never returns a value.

#include <iostream>
using namespace std;

int count=0;

class num {
    public:
    num() {
        count++;
        cout<<"this is the time the constructor is called for object number"<<count<<endl;
        
        
    }
    ~num(){
        cout<<"this is the time the destructor is called for object number"<<count<<endl;
        count--;
    }
};
 int main() {
    cout<<"we are inside our main function"<<endl;
    cout<<"creating first object n1 "<<endl;
    num n1;
    {
        cout<<"Entering this block"<<endl;
        cout<<"creating two more object  "<<endl;
        num n2,n3;
        cout<<"Exiting this block"<<endl;
    }
    cout<<"back to main function"<<endl;
    
    return 0;
}