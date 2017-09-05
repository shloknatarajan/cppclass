#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {
    string name;
    float gross, fed, state, ss, med, pension, health, net;
    ofstream fout;
    cout << "Employee name: ";
    getline(cin, name);
    cout << "Gross Pay: ";
    cin >> gross;
    fout.open("pay.txt");

    // Calculations of taces
    fed = gross * 0.15;
    state = gross * 0.035;
    ss = gross * 0.0575;
    med = gross * 0.0275;
    pension = gross * 0.05;
    health = 75;
    net = gross - fed - state - ss - med - pension - health;

    //Printing Data
    fout << "\n" << name << endl;
    fout << setw(18) << left << setfill('.') <<  "Gross Amount: ";
    fout << setw(18) << setprecision(2) << fixed << right << setfill('.') << gross << endl;
    fout << setw(18) << left << setfill('.') <<  "Federal Tax: ";
    fout << setw(18) << right << setfill('.') << fed << endl;
    fout << setw(18) << left << setfill('.') <<  "State Tax: ";
    fout << setw(18) << right << setfill('.') << state << endl;
    fout << setw(25) << left << setfill('.') <<  "Social Security Tax: ";
    fout << setw(11) << right << setfill('.') << ss << endl;
    fout << setw(25) << left << setfill('.') <<  "Medicare/Medicaid Tax: ";
    fout << setw(11) << right << setfill('.') << med << endl;
    fout << setw(18) << left << setfill('.') <<  "Pension Plan: ";
    fout << setw(18) << right << setfill('.') << pension << endl;
    fout << setw(18) << left << setfill('.') <<  "Health Insurance: ";
    fout << setw(18) << right << setfill('.') << health << endl;
    fout << setw(18) << left << setfill('.') <<  "Net Pay: ";
    fout << setw(18) << right << setfill('.') << net << endl;
    
    /*cout.width(45);
    cout << setfill('*') << setw(45);
    cout << left << "hi" << right << "Hola Amigos" << endl;*/


    
}
