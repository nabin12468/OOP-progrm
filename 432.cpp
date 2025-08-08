//overloading operator
#include<iostream>
#include<conio.h>
using namespace std;
class number{
	private:
		int value;
		public:
		number(int v){
			value=v;
		}	
		bool operator >(number n){
		return value > n.value;
			
		}
		void display(){
			cout<<value;
		}
	};
	int main(){
		number num1 (100);
		number num2(200);
		cout<<"First Number:";
		num1.display();cout<<endl;
		cout<<"Second Number:";
		num2.display();cout<<endl;
		cout<<"Largest Number is:";
		if (num1>num2)
			num1.display();
			else
			num2.display();
			return 0;
	}
	