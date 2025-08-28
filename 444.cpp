// File handling in C++

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string st="Harry bhai";
    // opening files using constructor and writing it
    string st2;

   // ofstream out("sample.txt");  //write operation
   // out<<st;
 ifstream in ("sample.xtx"); //read operation
 getline(in,st2);
 cout<<st2;
    return 0;
}