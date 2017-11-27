#include <iostream>
#include <cmath>
using namespace std;

enum mathStudent {John, Bill, Cindy, Lisa, Ron};
enum compStudent {Susan, Cathy, William};

int myFunc(int, int);

int myFunc(int x, int y) {
    return 1;
}

void main() {
    int x = 0;
    int y = 0;
    cin >> myFunc(x, y);
}
