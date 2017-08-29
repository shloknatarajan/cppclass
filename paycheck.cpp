#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    string name;
    float gross, fed, state, ss, med, pension, health, net;
    cout << "Employee name: ";
    getline(cin, name);
    cout << "Gross Pay: ";
    cin >> gross;

    // Calculations of taces
    fed = gross * 0.15;
    state = gross * 0.035;
    ss = gross * 0.0575;
    med = gross * 0.0275;
    pension = gross * 0.05;
    health = 75;
    net = gross - fed - state - ss - med - pension - health;

    //Printing Data
    cout << "\n" << name << endl;
    cout << setw(18) << left << setfill('.') <<  "Gross Amount: ";
    cout << setw(18) << setprecision(2) << fixed << right << setfill('.') << gross << endl;
    cout << setw(18) << left << setfill('.') <<  "Federal Tax: ";
    cout << setw(18) << right << setfill('.') << fed << endl;
    cout << setw(18) << left << setfill('.') <<  "State Tax: ";
    cout << setw(18) << right << setfill('.') << state << endl;
    cout << setw(25) << left << setfill('.') <<  "Social Security Tax: ";
    cout << setw(11) << right << setfill('.') << ss << endl;
    cout << setw(25) << left << setfill('.') <<  "Medicare/Medicaid Tax: ";
    cout << setw(11) << right << setfill('.') << med << endl;
    cout << setw(18) << left << setfill('.') <<  "Pension Plan: ";
    cout << setw(18) << right << setfill('.') << pension << endl;
    cout << setw(18) << left << setfill('.') <<  "Health Insurance: ";
    cout << setw(18) << right << setfill('.') << health << endl;
    cout << setw(18) << left << setfill('.') <<  "Net Pay: ";
    cout << setw(18) << right << setfill('.') << net << endl;
    
    /*cout.width(45);
    cout << setfill('*') << setw(45);
    cout << left << "hi" << right << "Hola Amigos" << endl;*/


    
}
