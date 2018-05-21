#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct Magazine {
	string name;
	Magazine *next;
};

Magazine * cptr = NULL;
Magazine * fptr = NULL;

void add();
void remove();
void print();
int count();
void donate();
void exit();
void menu();

void add() {
	string input = "";
	Magazine *newMagazine;
	do {
		newMagazine = new Magazine;
		cout << "Name: ";
		getline(cin, newMagazine->name);

		if (fptr == nullptr) {
			cptr = fptr = newMagazine;
		} else {
			cptr = fptr;
			while (cptr->next != nullptr) {
				cptr = cptr->next;
			}

			cptr->next = newMagazine;
		}

		newMagazine->next = nullptr;
		cout << "Insert another? (Y/N): ";
		cin >> input;
		cin.ignore(80, '\n');
		newMagazine->next = nullptr;
	} while (input == "y" || input == "Y");
}

void remove() {
	cptr = fptr;
	if (cptr == nullptr) {
		cout << "None to remove." << endl;
	} else if (cptr->next == nullptr) {
		cout << "Deleted first in list " << cptr->name << "." << endl;
		cptr = fptr = nullptr;
		delete cptr;
	} else {
		while (cptr->next && cptr->next->next != nullptr) {
			cptr = cptr->next;
		}

		cout << "Deleted " << cptr->next->name << "." << endl;
		cptr->next = nullptr;
		delete cptr->next;
	}
}

void print() {
	cout << left;
	cout << setw(14) << "Name" << endl;

	cptr = fptr;
	while (cptr != nullptr) {
		cout << setw(14) << cptr->name << endl;
		cptr = cptr->next;
	}
}

int count() {
	int c = 0;
	
	cptr = fptr;
	while (cptr->next != nullptr) {
		c++;
		cptr = cptr->next;
	}

	// above statement doesn't account for nullptr as fptr
	if (fptr != nullptr)
		c++;

	return c;
}

void donate() {
	int c = count();
	int toDonate = (int)floor((double)c/2);

	if (c == 0) {
		cout << "No magazines." << endl;
	} else if (toDonate == 0) {
		cout << "Only 1 magazine." << endl;
	} else {
		cptr = fptr;
		for (int i = 0; i < toDonate; i++) {
			remove();
		}

		cout << "Donated " << toDonate << " magazines." << endl;
	}
}

void menu() {
	int input = 0;

	while (true) {
		cout << "Choose from options: " << endl;
		cout << "1. Add" 	<< endl;
		cout << "2. Remove" << endl;
		cout << "3. Print" 	<< endl;
		cout << "4. Count" 	<< endl;
		cout << "5. Donate" << endl;
		cout << "6. Exit" 	<< endl;
		cout << "Choice: ";

		do {
			cin >> input;
			cin.ignore(80, '\n');
			if (input < 1 || input > 6) {
				cout << "Invalid input." << endl;
				cout << "Choice: ";
			}
		} while (input < 1 || input > 6);

		switch (input) {
			case 1:
				add();
				break;
			case 2:
				remove();
				break;
			case 3:
				print();
				break;
			case 4:
				cout << count() << " magazines." << endl;
				break;
			case 5: 
				donate();
				break;
			case 6:
				exit(0);
				break;			
		}

		cout << endl << endl;
	}
}

int main() {
	menu();
}