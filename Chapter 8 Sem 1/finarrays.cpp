#include <iostream>
#include <fstream>

using namespace std;

const int COUNT = 7;
void getData(ifstream & inf, int nums[]);
void print(int nums[]);
int main() {

    ifstream fin;
    fin.open("streamVariablesFile.txt");
    
    int nums[COUNT];

    if(!fin) {
        cout << "Can't open input file" << endl;
        cout << "Program terminates" << endl;
        return 1;
    }

    getData(fin, nums);
    print(nums);
    return 0;
}

void getData(ifstream & inf, int nums[]) {
    for(int i = 0; i < COUNT; i++) {
        inf >> nums[i];
    }    
}

void print(int nums[]) {
    for(int i = 0; i < COUNT; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}