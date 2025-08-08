// destructor

#include<iostream>
#include<conio.h>
using namespace std;
class test{
	int x,y;
	public:
		test(){
			x=100;
			y=200;
			cout<<"Memory is allocated:"<<endl;
		}
		 ~test()
		 {
		 	cout<<"x="<<x<<endl<<"y="<<y<<endl;
		 	cout<<"Memory is deallocated"<<endl;
}		 
};
int main(){
	test p;
	return 0;
}