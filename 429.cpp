// overload assignment operator
#include<iostream>
#include<conio.h>
using namespace std;
class marks{
	private:
		int m1,m2;
		public:
			marks(){
				m1=0;
				m2=0;
			}
			marks(int i,int j){
				m1=i;
				m2=j;
			}
			void operator =(const marks&m){
				m1=m.m1;
				m2=m.m2;
			}
			void display(){
				cout<<"Marks in 1st subject:"<<m1<<endl;
				cout<<"Marks in 2st subject:"<<m2<<endl;
		}
};
int main(){
marks mark1(45,89);
marks mark2(36,59);
cout<<"Marks of first student:"<<endl;
mark1.display();
cout<<"Marks of second student:"<<endl;
mark2.display();
mark1=mark2;
cout<<"Mark in 1st subject:"<<endl;
mark1.display();
return 0;
}