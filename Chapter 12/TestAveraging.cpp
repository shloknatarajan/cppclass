#include <iostream>
#include <iomanip>
using namespace std;

int* allocate(int ARRAY_SIZE) {
    int *arraypoint = new int[ARRAY_SIZE];
    if (arraypoint != NULL) {
        return arraypoint;

    } else {
        cout << "Memory allocation unsuccesful" << endl;
    }   
}


void getTests(int* p, int size) {
    for(int i = 0; i < size; i++) {
        cout << "Enter a test score: ";
        cin >> p[i];
    }
}

void sortIt(int* p, int elems)		
{					
					
	int startPos, minIndex; 
	int minValue;

	for (startPos = 0; startPos < (elems - 1); startPos++)
	{
		minIndex = startPos;
		minValue = p[startPos];

		for(int i = startPos + 1; i < elems; i++)
		{
			if (p[i] < minValue)
			{
				minValue = p[i];
				minIndex = i;
			}
		}

		p[minIndex] = p[startPos];
		p[startPos] = minValue;
	}
}

void printTests(int* p, int size) {
    cout << "\nScores\n----------\n";
    for(int i = 0; i < size; i++) {
        cout << fixed << showpoint << setprecision(2) << (double)p[i] << endl;
    }
}

double average(int* p, int size) {
    int sum = 0;
    int d = 0;
    for (int i = 0; i < size; i++) {
        sum += p[i];
        d++;
    }        
    return (double)sum / d;
}

int main() {
    int size;
    cout << "How many test scores will you enter? ";
    cin >> size;
    int* scores = allocate(size);
    getTests(scores, size);
    sortIt(scores, size);
    printTests(scores, size);
    cout << "\nAverage Score: " << fixed << showpoint << setprecision(2) << average(scores, size) << endl;
    return 0;
}