#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int sales[5];

void getsales();
string stars();

void getsales() {
    cout << "Enter today's sales for store 1: ";
    cin >> sales[0];
    cout << "Enter today's sales for store 2: ";
    cin >> sales[1];
    cout << "Enter today's sales for store 3: ";
    cin >> sales[2];
    cout << "Enter today's sales for store 4: ";
    cin >> sales[3];
    cout << "Enter today's sales for store 5: ";
    cin >> sales[4];
}

string stars(int sales) {
    string s = "";
    for (int i = 0; i < sales/100; i++) {
        s+="*";
    }

    return s;
}

void main() {
    getsales();
    cout << "Sales Bar Chart\n";
    for (int i = 0; i < 5; i++) {
        cout << "Store " << i+1 << ": " << stars(sales[i]) << endl;
    }
}