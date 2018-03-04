#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	struct Player {
		string name;
		int number;
		int score;
	};

	struct Player players[4];

	cout <<"--- Player 1 ---\n";
	cout << "Name: ";
	getline(cin, players[0].name);
	cout << "Number: ";
	cin >> players[0].number;
	cout << "Score: ";
	cin >> players[0].score;
	
	for (int i = 1; i < 4; i++) {
		cout << "--- Player " << i + 1 << " ---" << endl;
		cout << "Name: ";
		cin.ignore();
		getline(cin, players[i].name);
		cout << "Number: ";
		cin >> players[i].number;
		cout << "Score: ";
		cin >> players[i].score;
	}

	Player highest = players[0];
	int points = 0;
	cout << endl;
	cout << left << setw(20) << "NAME" << setw(10) << "NUMBER" << setw(10) << "POINTS" << endl;
	for (int i = 0; i < 4; i++) {
		cout << left << setw(20) << players[i].name << setw(10) << players[i].number << setw(10) << players[i].score << endl;

		points += players[i].score;
		if (players[i].score > highest.score)
			highest = players[i];
	}
	
	cout << "TOTAL POINTS: " << points << endl;
	cout << "The player who score the most points is: " << highest.name << endl;
	

	return 0;
}