#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << "Candidate count: ";
	int count;
	cin >> count;

	string *names = new string[count];
	int *votes = new int[count];

	int totalVotes = 0;
	int maxVotesIndex = 0;
	int maxVotes = 0;
	for (int i = 0; i < count; i++) {
		cout << "Last name: ";
		cin >> names[i];
		cout << "Votes: ";
		cin >> votes[i];

		totalVotes += votes[i];

		if (votes[i] > maxVotes) {
			maxVotes = votes[i];
			maxVotesIndex = i;
		}
	}


	cout << "Results" << endl;
	cout << showpoint << setprecision(2) << fixed << setfill(' ');
	cout << left << setw(12) << "Candidate" << setw(20) << "Votes Recieved" << setw(20) << "% Of Total Votes" << endl;
	for (int i = 0; i < count; i++) {
		cout << left << setw(12) << names[i] << setw(20) << votes[i] << setw(20) << (double)votes[i]/totalVotes*100 << endl;
	}
    cout << endl;
	cout << left << setw(12) << "Total" << setw(12) << totalVotes << endl;
	cout << left << setw(12) << "Winner: " << names[maxVotesIndex] << endl;
}