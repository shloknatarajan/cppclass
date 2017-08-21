#include <iostream>
#include <string>
#include "stdafx.h"
using namespace std;

int main() {
	char initial1, initial2;
	int num, day, month, year;
	int num1, num2, num3, num4, num5;

	cout << "Enter your first initial: ";
	cin >> initial1;

	cout << "Enter your last initial: ";
	cin >> initial2;

	cout << "Enter your favorite number: ";
	cin >> num;

	cout << "Enter your birth month day and year: ";
	cin >> month >> day >> year;

	cout << "Enter five scores: ";
	cin >> num1 >> num2 >> num3 >> num4 >> num5;

	cout << "Favorite #: \t\t" << num << endl;
	cout << "Birthday: \t\t" << month << "/" << day << "/" << year << endl;
	cout << "Age: \t\t\t" << 2017 - year << endl;
	cout << "avg: \t\t\t" << ((double)(num1 + num2 + num3 + num4 + num5) / 5) << endl;

	return 0;
}