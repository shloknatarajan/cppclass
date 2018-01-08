#include <iostream>
#include <cmath>
#include <string>
using namespace std;

enum mathStudent {John, Bill, Cindy, Lisa, Ron};
enum compStudent {Susan, Cathy, William};

int myFunc(int, int);

int myFunc(int x, int y) {
    return 1;
}

void main() {
    string str = "goofy";
    string newStr ="";

    for(int i=0; i < str.length(); i++) {
        cout << "str[" << i << "] + " << newStr;
        newStr=str[i] + newStr;
        cout << "= " << newStr << endl;
    }

    cout << "newStr: " << newStr << endl;
}
