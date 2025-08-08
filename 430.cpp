// copy constructor
#include<iostream>
#include<conio.h>
using namespace std;
class copyconstructor{
	private:
		int value;
		public:
			 copyconstructor(){
			 	cout<<"Enter an integer:";
			 	cin>>value;
			 }
			 copyconstructor(const copyconstructor &obj){
			 	value=obj.value;
			 }
			 void display(){
			 	cout<<"value:"<<value<<endl;
			 }
};
int main(){
	copyconstructor obj1;
	copyconstructor obj2=obj1;
	cout<<"object1:";
	obj1.display();
	cout<<"object 2 (copied from object 1):";
	obj2.display();
	return 0;
}