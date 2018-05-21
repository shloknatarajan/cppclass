#include <iostream>
#include "Chapter 10/Date.h"
#include "Chapter 10/Date.cpp"
using namespace std;

int main() {
    
    Date *d = new Date();
    getData(*d);
    (*d).printAll1();
    (*d).printAll2();
    (*d).printAll3();

    return 0;
}
