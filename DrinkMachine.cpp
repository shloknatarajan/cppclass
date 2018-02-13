#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	struct Drink {
		string name;
		double cost;
		int count;
	};

	struct Drink drinks[5] = {
		{ "Cola", 		.75, 20 },
		{ "Root Beet", 	.75, 20 },
		{ "Lemon-Lime", .75, 20 },
		{ "Grape Soda",	.80, 20 },
		{ "Cream Soda", .80, 20 }
	};

	int choice;
	double money;
	double earnings;

	while(true) {
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << " - " << drinks[i].name << endl;
		}
		cout << "6 - Exit" << endl;
		cout << "Choice: ";
		cin >> choice;
		if (choice == 6) {
			cout << endl << "Total earnt today is $" << earnings << "." << endl;
			exit(0);
		}

		money = 0;
		while (money == 0 || money < drinks[choice].cost) {
			cout << "Money: ";
			cin >> money;

			if (money < drinks[choice].cost)
				cout << "Not enough inserted, returning money" << endl;
		}

		drinks[choice].count--;
		earnings += drinks[choice].cost;

		cout << "Enjoy your drink!" << endl;
		cout << "Your change is $" << money - drinks[choice].cost << "." << endl;
		cout << "There are " << drinks[choice].count << " of type " << drinks[choice].name << " left." << endl;
		cout << endl << endl << endl;
	}

	return 0;
}