#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    int year;
    bool leap = false;
    string isleap;
    cout << "Current Year: " << endl;
    cin >> year;
    
    if (year % 4 == 0) {
        if (year % 100 != 0) {
            leap = true;
        } else if (year % 400 == 0) {
            leap = true;
        } else {
            leap = false;
        }
    }

    if (leap) {
        isleap = "yes";
    } else {
        isleap = "no";
    }

    cout << isleap << endl;
}