#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
using namespace std;

class Date {
    private:
        int month;
        int day;
        int year;
        string monthNames[12];
    public:
        // constructors 
        Date();
        Date(int, int, int);

        // functions
        void setNames();
        void setMonth(int);
        void setDay(int);
        void setYear(int);
        int getMonth();
        int getDay();
        int getYear();
        string getArrayMonth(int);

        // Printers
        void printAll1();
        void printAll2();
        void printAll3();

        
};
#endif