// informationn of student 

#include <iostream>
using namespace std;

class student {
private:
    string name, address, faculty;
    int roll_no;
public:
    void input() {
        cout << "Enter the name of student: ";
        cin >> name;
        cout << "Enter the Address of Student: ";
        cin >> address;
        cout << "Enter the faculty of Student: ";
        cin >> faculty;
        cout << "Enter the Rollno of Student: ";
        cin >> roll_no;
        cout << endl;
    }

    void display() {
        cout << "Student info :" << endl;
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Roll No : " << roll_no << endl;
    }
};

int main() {
    student s;
    s.input();
    s.display();

    return 0;
}