//static data member and fuction
#include<iostream>
#include<conio.h>
using namespace std;
class Static{
	private:
	int a;
	static int b;
	public:
		Static(int x,int y){
			a=x;
			b=y;
		}
		void show(){
			cout<<a<<" "<<b;
		}
		static void display(){
			cout<<b;
		}
};
int Static::b=0;
int main(){
	Static s1(10,20),s2(100,200);
	s1.show();
	cout<<endl;
	s2.show();
	cout<<endl;
	Static::display();
	cout<<endl;
	s1.show();
	return 0;
	
	
}