#include "Date.h"
#include "Date.cpp"
#include <iostream>
using namespace std;
int main() {
    Date d = Date(12, 23, 1);
    getData(d);
    cout << "\n3 Different Print outs: \n";
    d.printAll1();
    d.printAll2();
    d.printAll3();

    return 0;
}