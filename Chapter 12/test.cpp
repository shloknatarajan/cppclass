#include <iostream>
using namespace std;

int main() {
    int x = 50, y = 60, z = 70;
    int *p;
    cout << x << " " << y << " " << z << endl;
    p = &x;
    *p *= 10;
    p = &y;
    *p *= 5;
    p = &z;
    *p *= 2;
    cout << x << " " << y << " " << z << endl;

}