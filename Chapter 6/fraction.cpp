#include <iostream>
#include <iomanip>
using namespace std;

// Global Variables
int num = 0, denom = 0;

// Function Prototypes
int greatestcommonfactor(int a, int b);
void reduce (int &num, int &denom, int gcf);

// Main
int main() {
    int gcf = 1;
    cout << "Enter Numerator: ";
    cin >> num;
    cout << "\nEnter Denominator: ";
    cin >> denom;
    while (denom == 0) {
        cout << "\nEnter a Nonzero Denominator: ";
        cin >> denom;
    }

    gcf = greatestcommonfactor(num, denom);

    reduce(num, denom, gcf);
    
    return 0;
}

void reduce (int &num, int &denom, int gcf) {
    cout << setw(26) << setfill('-') << right << "Fraction Reducer" << setw(9) << right << "-" << endl;;
    cout << "Numerator: " << num << endl;
    cout << "Denominator " << denom << endl;
    
    cout << num << "/" << denom << " = ";
    if (num % denom == 0) {
        cout << (num/denom);
    } else {
        cout << (num/gcf) << "/" << (denom/gcf);
    }
}

int greatestcommonfactor(int a, int b) {
    int temp, gcf;
    if (a > b) {
        temp = a;
    } else {
        temp = b;
    }

    for (int i = 1; i < temp; i++) {
        if ((a % i == 0) && (b % i == 0)) {
            gcf = i;
        }   
    }

    return gcf;
}