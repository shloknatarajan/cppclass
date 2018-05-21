#include <iostream>
using namespace std;
int* allocate(int ARRAY_SIZE) {
    int *arraypoint = new int[ARRAY_SIZE];
    if (arraypoint != NULL) {
            cout << "Array of size " << ARRAY_SIZE << " created" << endl;
        return arraypoint;
    } else {
        cout << "Memory allocation unsuccesful" << endl;
    }   
}

int main() {
    int n;
    cout << "Array Size: ";
    cin >> n;
    allocate(n);
    return 0;
}