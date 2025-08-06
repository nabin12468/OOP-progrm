 //Write a program in c++ to demostrate the use of inline function
#include<iostream>
#include<conio.h>
using namespace std;
inline void sum(int x,int y){
	int s;
	s=x+y;
	cout<<"Sum of two number is:="<<s<<endl;
	s=x-y;
	cout<<"Difference of two number is:="<<s<<endl;
}
int main(){
	int a,b;
	cout<<"Enter the two Numbers"<<endl;
	cin>>a>>b;
	sum(a,b);
	return 0;
}