#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 7;
int empIds[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
int hours[SIZE] = {-1};
double payRate[SIZE] = {-1};
double wages[SIZE];

void display(int);
void getHoursPay(int);
void calcWages(int);

int main() {
	fill(hours, hours + 7, -1);
	fill(payRate, payRate + 7, -1);
	for(int i = 0; i < 7; i++) {
		cout << "Employee (" << empIds[i] << "): " << endl;
		getHoursPay(i);
		calcWages(i);
	}

	cout << setprecision(2) << showpoint << fixed << endl;
	cout << left << setw(9) << "Id" << setw(6) << "Hours" << setw(9) << "Rate" << setw(9) << "Pay" << endl;
	cout << left << setw(9+6+8+8+2) << setfill('-') << "-" << endl;
	for (int i = 0; i < 7; i++)
		display(i);


	return 0;
}

void getHoursPay(int i) {
	while(hours[i] < 0) {
		cout << "\tHours worked: ";
		cin >> hours[i];

		if (hours[i] < 0)
			cout << "\tHours cannot be negative." << endl;
	}

	while(payRate[i] < 6) {
		cout << "\tPay rate: ";
		cin >> payRate[i];

		if (payRate[i] < 6)
			cout << "\tPay rate cannot be less than $6.00/hr" << endl;
	}
}

void calcWages(int i) {
	wages[i] = payRate[i]*hours[i];
}

void display(int i) {
	cout << setfill(' ');
	cout << left << setw(9) << empIds[i] << setw(6) << hours[i] << setw(1) << "$" << setw(8) << payRate[i] << setw(1) << "$" << setw(8) << wages[i] << endl;
}