#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

Date::Date() {
    setNames();
    setMonth(1);
    setDay(1);
    setYear(1990);
}

Date::Date(int m, int d, int y) {
    setNames();
    setMonth(m);
    setDay(d);
    setYear(y);
}

void Date::setNames() {
    monthNames[0] = "January";
    monthNames[1] = "February";
    monthNames[2] = "March";
    monthNames[3] = "April";
    monthNames[4] = "May";
    monthNames[5] = "June";
    monthNames[6] = "July";
    monthNames[7] = "August";
    monthNames[8] = "September";
    monthNames[9] = "October";
    monthNames[10] = "November";
    monthNames[11] = "December";
}

string Date::getArrayMonth(int a) {
    return monthNames[a-1];
}


void Date::setMonth(int m) {
    if (m > 12 || m < 1) {
        cout << "Invalid Month" << endl;
    } else {
        month = m;
    }
}

void Date::setDay(int d) {
    if (d > 31 || d < 1) {
        cout << "Invalid Day" << endl;
    } else {
        day = d;
    }
}

void Date::setYear(int y) {
    if (y < 100) {
        cout << "Invalid Year" << endl;
    } else {
        year = y;
    }
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

int Date::getYear() {
    return year;
}

void Date::printAll1() {
    cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}

void Date::printAll2() {
    cout << getArrayMonth(getMonth()) << " " << getDay() << ", " << getYear() << endl;
}

void Date::printAll3() {
    cout << getDay() << " " << getArrayMonth(getMonth()) << " " << getYear() << endl;
}

int main() {
    Date d = Date(12, 23, 1999);
    d.printAll1();
    d.printAll2();
    d.printAll3();

    return 0;
}
