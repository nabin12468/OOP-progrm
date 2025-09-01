//progrsm to access static data member using static member function
#include <iostream>
using namespace std;

class student{
    private:
    int roll;
    char name[20];
    static int count;
    public:
    void getdata()
    {
        cout<<"Enter roll no and name"<<endl;
        cin>>roll>>name;
        count++;
    }
    static void display()
    {
        
        cout<<"Count: "<<count<<endl;

    }

};
 int student::count=0;

int main() {
    student s1,s2,s3;
    student::display();
    s1.getdata();
    s1.display();   
    s2.getdata();
    s2.display();
    s3.getdata();
    s3.display();

    
    return 0;
}