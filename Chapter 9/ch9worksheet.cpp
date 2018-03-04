#include <iostream>
#include <string>

using namespace std;

void main() {
    struct nameType {
        string first;
        string last;
    };

    struct dataType {
        int month;
        int day;
        int year;
    };

    struct personalInfoType {
        nameType name;
        int pID;
        dataType dob;
    };

    struct employeeType {
        nameType name;
        int performanceRating;
        int pID;
        string dept;
        double salary;
    };

    employeeType employees[100];
    employeeType newEmployee;

    // Testing Area Below
    newEmployee = {{"Mickey", "Doe"}, 2, 111111111, "ACCT", 234234};
    
}