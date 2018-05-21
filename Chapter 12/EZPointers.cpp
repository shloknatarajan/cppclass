#include <iostream>
using namespace std;
int main() {
    double a, b;
    double *point;
    point = &a;
    *point = 1.25;
    point = &b;
    *point = 2.5;
    cout << "A: " << a << endl << "B: " << b;
    return 0;
}