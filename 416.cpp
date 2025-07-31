// program to read contents of a text file and display it on the screen using insertion operator

#include <iostream>
#include <fstream> // Required for ifstream
using namespace std;

int main()
{
    char str[100];
    ifstream fin;
    fin.open("abc.txt");
    if (!fin) {
        cout << "Unable to open file." << endl;
        return 1;
    }
    while (fin.getline(str, 99))
    {
        cout << str << endl;
    }
    fin.close();
    return 0;
}