#include "Mortgage.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

Mortgage::Mortgage() {
    setLoan(100000);
    setRate(0.05);
    setYear(30);
}

Mortgage::Mortgage(double l, double r, int y) {
    setLoan(l);
    setRate(r);
    setYear(y);
}

void Mortgage::setLoan(double l) {
    loan = l;
}

void Mortgage::setRate(double r) {
    rate = r;
}

void Mortgage::setYear(int y) {
    year = y;
}

double Mortgage::getLoan() {
    return loan;
}

double Mortgage::getRate() {
    return rate;
}

int Mortgage::getYear() {
    return year;
}

double Mortgage::term() {
    return pow((1+(rate/12)), 12*year);
}

double Mortgage::monthly() {
    double t = term();
    return (loan*(rate/12)*t)/(t-1);
}

void Mortgage::printAllData() {
    cout << "Loan: " << getLoan() << endl;
    cout << "Rate: " << getRate() << endl;
    cout << "Year: " << getYear() << endl;
    cout << "Monthly payment: " << "$" << fixed << showpoint << setprecision(2) << monthly() << endl;
    cout << "Total Pay Back: $" << fixed << showpoint << setprecision(2) << monthly() * 12 * year << endl;
}

int main() {

    double lo, ra;
    int ye;

    cout <<"Enter the loan amonut: ";
    cin >> lo;
    cout <<"Enter the interest rate: ";
    cin >> ra;
    cout <<"Enter in the number of years of the loan: ";
    cin >> ye;
    Mortgage m = Mortgage(lo, ra, ye);

    m.printAllData();

}

