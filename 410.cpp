// multiple inheritance
#include <iostream>
using namespace std;




class students{
    protected:
     int roll_number;
     public:
     void set_roll_number(int);
     void get_roll_number(void);
     
};

void student :: set_roll_number(int r)
{
    roll_number = r;
}
void student :: get_roll_number(int r)
{
    cout << "The roll number is: " << roll_number << endl;
}


int main()
{

    return 0;
}
















/*
 For protected member:
                    public derivation  private derivation  protected derivation

   1.private members  not inherited       not inherited        not inherited
   2.protected members  protected         private              protected
   3.public members      public              private              protected



*/