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

Magazine * curptr = NULL;
Magazine * headptr = NULL;

void add();
void remove();
void remove2();
void print();
int count();
void donate();
void exit();
void menu();
int search(string look4);

void remove() {
	curptr = headptr;
	if (curptr == nullptr) {
		cout << "None to remove." << endl;
	} else if (curptr->next == nullptr) {
		cout << "Deleted first in list " << curptr->name << "." << endl;
		curptr = headptr = nullptr;
		delete curptr;
	} else {
		while (curptr->next && curptr->next->next != nullptr) {
			curptr = curptr->next;
		}

		cout << "Deleted " << curptr->next->name << "." << endl;
		curptr->next = nullptr;
		delete curptr->next;
	}
}

void add() {
	string input = "";
	Magazine *newMagazine;
	do {
		newMagazine = new Magazine;
		cout << "Name: ";
		getline(cin, newMagazine->name);

		if (headptr == nullptr) {
			curptr = headptr = newMagazine;
		} else {
			curptr = headptr;
			while (curptr->next != nullptr) {
				curptr = curptr->next;
			}

			curptr->next = newMagazine;
		}

		newMagazine->next = nullptr;
		cout << "Insert another? (Y/N): ";
		cin >> input;
		cin.ignore(80, '\n');
		newMagazine->next = nullptr;
	} while (input == "y" || input == "Y");
}

int search(string look4) {
    curptr = headptr;
    int pos = 1;
	do {
		if (curptr->name == look4)
			//return curptr;
            return pos;
		else {
			curptr = curptr->next;
            pos++;
		}
	} while (curptr != NULL);

	return 0;		// Me - after function complete, NULL will only be returned if not found

	//don't call menu here - it is taken care of in the menu!
}

void remove2() {
    curptr = headptr;
    
    if (headptr == NULL) {
        cout << "No magazines to delete" << endl;
    } else {
        string toremove;
        cout << "Magazine to remove: " << endl;
        getline(cin, toremove);

        int pos = search(toremove);
        if (pos == 0) {
            cout << "Not Found" << endl;
        } else if (pos == 1) {
            headptr = headptr->next;
            curptr = headptr;
        } else {
            //cout << "pos: " << pos << endl;
            curptr = headptr;
            int count = 1;
            while (count < pos-1) {
                curptr = curptr->next;
                count++;
            }
            curptr->next = curptr->next->next;
        }
    }
    
    menu();
}

void print() {
	int x = 1;
    curptr = headptr;
    cout << "\n      Magazines\n---------------------\n";
    if (headptr != NULL) {
        while (curptr != NULL) {
            cout << x << ". " << curptr->name << endl;
            curptr = curptr->next;
            x++;
        }
        cout << endl;
    } else {
        cout << "No Magazines" << endl;
    }

    menu();
}

int count() {
	int c = 0;
	
	curptr = headptr;
	while (curptr->next != nullptr) {
		c++;
		curptr = curptr->next;
	}

	// above statement doesn't account for nullptr as headptr
	if (headptr != nullptr)
		c++;

	return c;
}

void donate() {
	int size = count();
    size /= 2;
    cout << "Split Top" << endl;
    if (size == 0) {
        cout << "No magazines to split!" << endl;
    } else {
        curptr = headptr;
        int count = 0;
        while (count < size-1) {
            curptr = curptr->next;
            count++;
        }
        curptr->next = NULL;
    }

    menu();
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
				remove2();
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