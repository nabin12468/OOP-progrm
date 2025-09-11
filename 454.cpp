#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 3, 5, 7, 9};

    // Reverse the vector
    reverse(v.begin(), v.end());

    for (auto i : v)
        cout << i << " ";
    return 0;
}