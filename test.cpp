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
 
    char name[8] = "shelly";
    char str2[8] = "abcdefg";
    int j = 0;
    while(j < 8) {
        cout << name[j++] << "_";
    }
}
