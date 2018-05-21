#include "die.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
int outcomes[13];
int times;


Die::Die () {
    srand(time(0)); // Avoids getting the same roll repeatadly
	rollDie();
}

void Die::rollDie () {
	value = ((rand() % 6) + 1);
}

int Die::getValue() {
    return value;
}

void displayTable () {
    //cout << "Times: " << times << endl;
	cout << setprecision(2) << showpoint << fixed;
	cout << setw(10) << "Roll Value" << setw(20) << "Times Rolled" << setw(20) << "% Occurence" << endl;

	cout << setw(10) << "2" << setw(20) << outcomes[2] << setw(20) << ((double)outcomes[2]/times)*100  << endl;
	cout << setw(10) << "3" << setw(20) << outcomes[3] << setw(20) << ((double)outcomes[3]/times)*100  << endl;
	cout << setw(10) << "4" << setw(20) << outcomes[4] << setw(20) << ((double)outcomes[4]/times)*100  << endl;
	cout << setw(10) << "5" << setw(20) << outcomes[5] << setw(20) << ((double)outcomes[5]/times)*100  << endl;
	cout << setw(10) << "6" << setw(20) << outcomes[6] << setw(20) << ((double)outcomes[6]/times)*100  << endl;
	cout << setw(10) << "7" << setw(20) << outcomes[7] << setw(20) << ((double)outcomes[7]/times)*100  << endl;
	cout << setw(10) << "8" << setw(20) << outcomes[8] << setw(20) << ((double)outcomes[8]/times)*100  << endl;
	cout << setw(10) << "9" << setw(20) << outcomes[9] << setw(20) << ((double)outcomes[9]/times)*100  << endl;
	cout << setw(10) << "10" << setw(20) << outcomes[10] << setw(20) << ((double)outcomes[10]/times)*100 << endl;
	cout << setw(10) << "11" << setw(20) << outcomes[11] << setw(20) << ((double)outcomes[11]/times)*100 << endl;
	cout << setw(10) << "12" << setw(20) << outcomes[12] << setw(20) << ((double)outcomes[12]/times)*100 << endl;
}

int main() {
    Die d = Die();
    cout << "Roll Count: ";
    cin >> times;

    // Initialize Array to Zero
    for (int i = 0; i < 13; i++) {
        outcomes[i] = 0;
    }

    // Populate array with real numbers
    int totalRoll;
    for (int i = 0; i < times; i++) {
        // Rolls Die Twice and then adds roll to array frequency
        totalRoll = 0;
        d.rollDie();
        totalRoll += d.getValue();
        d.rollDie();
        totalRoll += d.getValue();
        outcomes[totalRoll] += 1; // Counts the frequency of that roll
    }

    displayTable();

	return 0;
}