#ifndef MORTGAGE_H
#define MORTGAGE_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Mortgage {
    private:
        double loan;
        double rate;
        int year;

    public:
        Mortgage();
        Mortgage(double, double, int);

        void setLoan(double);
        void setRate(double);
        void setYear(int);

        double getLoan();
        double getRate();
        int getYear();

        double term();
        double monthly();

        void printAllData();
};
#endif