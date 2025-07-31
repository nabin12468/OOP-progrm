// program to convert hour into minutes.


#include <iostream>
using namespace std;
class Time {
    private:
        int hour;
    public:
        Time(int h){
            hour=h;

        }
        operator int() {
            return hour * 60; // converting hour to minutes
        }
        void display() {
            cout << "hours=" << hour  << endl;
        }
    };

    int main(){
        Time t(2); // 2 hours
        t.display();
        int minutes = t;
        cout<<"Total mintues:"<<minutes<<endl;
        return 0;
    }


