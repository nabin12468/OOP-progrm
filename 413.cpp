//program to rectangle to polor by class type conversion using constructor

#include <iostream>
#include <cmath> // Required for sqrt and atan2
using namespace std;

class rectangle {
public:
    float x, y;
    rectangle(float a, float b) {
        x = a;
        y = b;
    }
};

class polar {
public:
    float r, angle;
    polar(rectangle rect) {
        r = sqrt(rect.x * rect.x + rect.y * rect.y);
        angle = atan2(rect.y, rect.x); // angle in radians
    }

    void display() {
        cout << "radius = " << r << endl;
        cout << "angle (in radians) = " << angle << endl;
    }
};

int main() {
    rectangle rect(3, 9);
    polar p = rect; // implicit conversion
    p.display();
    return 0;
}