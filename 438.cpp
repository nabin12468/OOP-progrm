
/*Dynamic constructor is  used to allocate the memory to the objects at the run time.
/memory is allocated at the run time with the help of 'new' operator.

*/

#include <iostream>
using namespace std;

class example{
    int size;
    int *p;
public:
    example(int s) {
        size = s;
        p=new int[size]; // dynamic memory allocation
    }
    void input(){
        cout<<"enter the values"<<endl;
        for(int i=0;i<size;i++)
            cin>>p[i];
        
    }
     void output(){
        cout<<"the values entered by the user are"<<endl;
        for(int i=0;i<size;i++)
            cout<<p[i];
        }
    

};

int main() {

    int d;
    cout<<"enter the size of the array"<<endl;
    cin>>d;
    example e(d);
    e.input();
    e.output();
    
    return 0;
}