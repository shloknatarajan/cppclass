#include <string>
#include <iostream>

using namespace std;

template <class Type, int length>
Type getMin(Type a[length]) {
	Type minimum = a[0];

	for(int i = 0; i < length; i++) {
		if (a[i] < minimum) {
			minimum = a[i];
		}
	}

	return minimum;
}

template <class Type, int length>
void printArray(Type a[length]) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		//cout << i;
		if (i == length - 1)
			cout << a[i];
		else
			cout << a[i] << ", ";
	}
	cout << "]" << endl;
}

int main() {
	int intArray[15] = {8, 4, -9, 5, 7, 8, 3, 2, 9, -5, 9, 2, 1, 5, -3};
    string stringArray[15] = {"Dan", "Will", "Bryan", "Matt", "Nathan", "Alex", "Demitriy", "David", "Eric", "Steve", "Jason", "Sarvesh", "Kyle", "Nick", "Daphne"};
	double doubleArray[15] = {98.77, 89.6, 92.3, 96.4, 87.3, 95.5, 99.3, 99.55, 86.55, 87.335, 83.22, 88.66, 96.54, 92.69, 94.312};


	printArray<int, 15>(intArray);
    string me = "Minimum Element: ";
	cout << me << getMin<int, 15>(intArray) << endl << endl;
	printArray<double, 15>(doubleArray);
	cout << me << getMin<double, 15>(doubleArray) << endl << endl;
	printArray<string, 15>(stringArray);
	cout << me << getMin<string, 15>(stringArray) << endl << endl;



	return 0;
}