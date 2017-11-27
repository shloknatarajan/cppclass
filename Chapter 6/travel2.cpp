#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int people, instruction, renting;
double base = 0, instruct = 0, rent = 0, discount = 0;


void menu();
double climbing(int p, int i, int r);
double scuba(int p, int i);
double spelunking(int p, int r);
void getTotal();

int main() {
	menu();
	getTotal();
	return 0;
}

double climbing(int p, int i, int r) {
	base = p*350;
	instruct = i*100;
	rent = r*120;

	return p*350 + i*100 + r*120;
}

double scuba(int p, int i) {
	base = p*1000;
	instruct = i*100;

	return p*350 + i*100;
}

double spelunking(int p, int r) {
	base = p*700;
	rent = r*240;

	return p*700 + r*240;
}

void getTotal() {
    if (people >= 5) {
        discount = base*0.1;
    }

	ofstream fout;
	fout.open("travel.txt");

	fout << fixed << showpoint << setprecision(2);
	fout << left << setw(32) << setfill('.') << "Numer In Party" << " " <<setw(10) << setfill(' ') << right << people << endl;
	fout << left << setw(32) << setfill('.') << "Base Charges" << "$" << setw(10) << setfill(' ') << right << base << endl;
	fout << left << setw(32) << setfill('.') << "Discount" << "$" << setw(10) << setfill(' ') << right << base*.1 << endl;
	fout << left << setw(32) << setfill('.') << "Instruction Cost" << "$" << setw(10) << setfill(' ') << right << instruct << endl;
	fout << left << setw(32) << setfill('.') << "Equipment Rental" << "$" << setw(10) << setfill(' ') << right << rent << endl;
	fout << setw(40) << setfill('-') << "-" << endl;

	fout << left << setw(32) << setfill('.') << "Subtotal" << "$" << setw(10) << setfill(' ') << right << base + instruct + rent - discount<< endl;
	fout << left << setw(32) << setfill('.') << "Tax" << "$" << setw(10) << setfill(' ') << right << (base + instruct + rent- discount)*.05 << endl;
	fout << left << setw(32) << setfill('.') << "Total" << "$" << setw(10) << setfill(' ') << right << base + instruct + rent - discount + (base + instruct + rent - discount)*.05 << endl;
	fout << left << setw(32) << setfill('.') << "Deposit" << "$" << setw(10) << setfill(' ') << right << (base + instruct + rent - discount)*.5 << endl;
}

void menu() {
	int choice;
    cout << "High Adventure Travel Agency" << endl;
    cout << "----------------------------" << endl;
	cout << "1) Climbing " << endl;
	cout << "2) Scuba " << endl;
	cout << "3) Spelunking " << endl;
	cout << "4) Exit" << endl;

	cout << "Choice: ";
	cin >> choice;

	switch(choice) {
		case 1:
			cout << "People: ";
			cin >> people;
			cout << "Instruction: ";
			cin >> instruction;
			cout << "Renting: ";
			cin >> renting;

			climbing(people, instruction, renting);
			break;
		case 2:
		cout << "People: ";
			cin >> people;
			cout << "Instruction: ";
			cin >> instruction;

			scuba(people, instruction);
			break;
		case 3:
			cout << "People: ";
			cin >> people;
			cout << "Renting: ";
			cin >> renting;

			spelunking(people, renting);
			break;
		case 4:
			return;

	}
}