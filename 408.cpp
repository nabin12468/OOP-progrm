/* 1.single inheritance : A derived class with only one base class

    2.Multiple inheritance : A derived class with more than one base class

    3.Hierarchical inheritance :  several derived classes from a single base class

    4.Multilevel inheritance :  Deriving  a class from already derived class

    5.Hybrid inheritance :  A combination of two or more types of inheritance Or (is a combination of multiple inheritance and multilevel inheritance)





 */

 #include <iostream>
using namespace std;

class employee {  // base class
protected:
    int id;

public:
    float salary;
    employee(int inpId) {
        id = inpId;
        salary = 34.0;
    }
};


/** derived class syntax
class{{ derived-class-name}} :{{visibilit-mode}}{{ base-class-name}}{
    //body of class
}




note:1.
 2.public visibility mode:public members of base class become public members of derived class
 3.private visibility mode:public members of base class become private members of derived class
 4.private members are never inherited
*/

//creating a programmer class derived from employee base class

class programmer : public employee {
public:
    programmer(int inpId) : employee(inpId) { }
    int languageCode = 9;
    void getData() {
        cout << id << endl;
    }
};

int main() {
    employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    programmer skillF(10);
    cout << skillF.languageCode << endl;
    skillF.getData();
    return 0;
}

