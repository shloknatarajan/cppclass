#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struct
struct magazine {
    string title;
    magazine* next;
};

// Initializing global pointer variables
magazine *headptr = NULL;
magazine *curptr = NULL;

// Method Prototypes
void add();
void remove();
void printAll();
int totalMagazines();
void splitCollection();
void menu();
int search(string look4);

// Method Definitions
void splitCollection() {
    int size = totalMagazines();
    size /= 2;
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
        cout << "Split Collection" << endl;
    }
}

void add() {
    curptr = headptr;
	string n;

	do
	{
		cout<<"Enter title of magazine: " << endl;
        cin.ignore(80, '\n');
		getline(cin, n);

		if(n!="")
		{
            //declare and initialize the new node
            magazine* newMag = new magazine;

            newMag->title = n;
            //cout << "newMag->title = " << newMag->title << endl;
            

            newMag->next = NULL;   //last one on the list always points to NULL

            //move curptr to the end of the list, then point it to newSchool

            if(headptr != NULL)
            {
                while(curptr->next != NULL) //while not at end of the list
                {
                    curptr = curptr->next; //go to next node
                }

                curptr->next = newMag; //new node is at the end of the list
            }
            else
            {
                headptr = curptr = newMag;  //add the first one!
            }
		}

	} while(n=="");


}

void remove() {
    curptr = headptr;
    
    if (headptr == NULL) {
        cout << "No magazines to delete" << endl;
    } else {
        string toremove;
        cout << "Magazine to remove: " << endl;
        cin.ignore(80,'\n');
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
    
}

int search(string look4) {
    curptr = headptr;
    int pos = 1;
	do {
		if (curptr->title == look4)
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

int totalMagazines() {
    curptr = headptr;
    int count = 0;

    if (headptr != NULL) {
        count++;
    } else {
        return 0;
    }

    while (curptr->next != NULL) {
        curptr = curptr->next;
        count++;
    }

    //cout << "Total Magazines: " << count << endl;
    return count;

}

void printAll() {
    int x = 1;
    curptr = headptr;
    cout << "\n      Magazines\n---------------------\n";
    if (headptr != NULL) {
        while (curptr != NULL) {
            cout << x << ". " << curptr->title << endl;
            curptr = curptr->next;
            x++;
        }
        cout << endl;
    } else {
        cout << "No Magazines" << endl;
    }

  
}





void menu() {
    int choice = 0;
    cout << "Options\n----------\n1. Add Magazine\n2. Remove Magazine\n3. List Total\n4. Print Collection\n5. Split Collection\n6. Exit" << endl;
    cin >> choice;
    /*if (choice == 1 ) {
        add();
    } else if (choice == 2) {
        remove();
    } else if (choice == 3) {
        cout << "Total magazines: " << totalMagazines() << endl;
    } else if (choice == 4) {
        printAll();
    } else if (choice == 5) {
        cout << "Splitting" << endl;
        splitCollection();
    } else if (choice == 6) {

    } else {
        cout<<"Error!  Try again...\n\n";
    }*/
    bool playing = true;
    
    switch(choice) {
        case 1:
            add();
            break;
        
        case 2:
            remove();
            break;
        
        case 3:
            cout << "Total magazines: " << totalMagazines() << endl;
            break;
        
        case 4:
            printAll();
            break;
        
        case 5:
            splitCollection();
            break;
        
        case 6: 
            playing = false;
            break;
        
        default:
			cout<<"Error!  Try again...\n\n";
            break;
        
    }
    if (playing) {
        menu();
    }
    
}

int main() {
    menu();
    return 0;
}

