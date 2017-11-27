#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void menu();
char getInput();
void handleInput();
void kaboom();
void averages();
void rect();
void cls();

void menu() {
	cout << "1: Kaboom" << endl;
	cout << "2: Averages" << endl;
	cout << "3: Draw Rectangle" << endl;
	cout << "4: Cls" << endl;
	cout << "5: Quit" << endl;
}

char getInput() {
	char c;
	cout << "Input: ";
	cin >> c;
	return c;
}

void handleInput(char c) {
	cout << endl;
	switch(c) {
		case '1':
			kaboom();
			break;
		case '2':
			averages();
			break;
		case '3':
			rect();
			break;
		case '4':
			cls();
			break;
		case '5':
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Invalid input!" << endl;
	}
}

void kaboom() {
	for (int i = 10; i >= 0; i--) {
		if (i != 0) {
			cout << i << "...";
		} else {
			cout << "Kaboom!" << endl;
		}
	}
}

void averages() {
	char c;
	int num = 0, sum = 0, count = 0;

	fflush(stdin);
	cin.ignore(80, '\n');

	while (c != 'q' && c != 'Q') {
		cin.putback(c);
		cin >> num;
		cin.ignore(80, '\n');

		count++;
		sum += num;

		cin.get(c);
	}

	cout << "Average: " << (double)sum/count << endl << endl;
}

void rect() {
	int x, y;
	cout << "Enter dimensions: ";
	cin >> x >> y;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

void cls() {
	system("cls");
}

int main() {
	bool looping = true;

	while (looping) {
		menu();
		handleInput(getInput());
	}

	return 0;
}