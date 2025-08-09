//macro function

#include <iostream>
#define mul(a,b) ((a)*(b))
#define div(a,b) ((a)/(b))
using namespace std;

int main() {
    int x = 2, y = 3;
    float n = 5.0, m = 2.0;
    cout << mul(x, y);
    cout << "\n";
    cout << div(n, m);
    cout << "\n";
    // getch(); // Uncomment if using Turbo C++ or similar
    return 0;
}