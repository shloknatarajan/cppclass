// Linked Lists Example

// schoolList.cpp : This program uses a linked list to keep track of schools.
//                  It is incomplete!!!  Your assignment is to finish it.
//                  Read the comments to help you.

// Me - Functions Add and Print work           Delete and Search done by student in exercises


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//global structure definitions and vars

struct highschool
{
	string sname;   //name of school
	string mascot;    //mascot
	int fyear;        //year
	highschool *next;   //link to next node (each piece of data is a node)
};

highschool *headptr = NULL;   //this points to the first node on the list
highschool *curptr = NULL;   //this points to current position on the list


void addschool(string);   //adds a new school to the end of the linked list
void menu();			  //pulls up the menu of choices
void add();				  //prompts the user for a nonblank school name to plug into addschool function call
void remove();			  //remove a school from the end of the list, or says none to remove - NO ERRORS!
void printall();		  //print out all schools in a numbered list.

/*search function: searches for a string name of school,
returns by reference position of the school and a pointer
to the school that is NULL if school is not found on the list.*/

highschool* search(string, int &);

int main()
{
	curptr = headptr;   //at start - current pointer is at the head of list

	menu();

	return 0;
}

void addschool(string x)
{
	//declare and initialize the new node
	highschool *newSchool = new highschool;

	newSchool->sname = x;
	cout<<"Please enter the year that " <<x<<" was founded: ";
	cin>>newSchool->fyear;
	cin.ignore(80, '\n');

	cout<<"School mascot? ";
	getline(cin, newSchool->mascot);

	newSchool->next = NULL;   //last one on the list always points to NULL

	//move curptr to the end of the list, then point it to newSchool

	if(headptr != NULL)
	{
		while(curptr->next != NULL) //while not at end of the list
		{
			curptr = curptr->next; //go to next node
		}

		curptr->next = newSchool; //new node is at the end of the list
	}
	else
	{
		headptr = curptr = newSchool;  //add the first one!
	}

}

void add()
{
	string n;

	do
	{
		cout<<"\nEnter name of school: ";
		getline(cin, n);

		if(n!="")
		{
			addschool(n);
		}

	} while(n=="");

	menu();
}

void remove()
{	
	curptr = headptr;
	if (headptr == NULL) {
		cout << "No schools to delete." << endl;
	} else {
		if (headptr->next == NULL) {
			delete headptr;
			headptr = NULL;
		} else {
			curptr = headptr;
			highschool *tempptr;

			while (curptr->next != NULL) {
				tempptr = curptr;
				curptr = curptr->next;
			}

			delete curptr;
			curptr = NULL;
			tempptr->next = NULL;
		}
	}

	

	menu();
}

void printall()
{
	if(headptr != NULL)					//only print if the list isn't empty!
	{
		curptr = headptr;				//put current pointer at the head!

		int x = 0; //row number

		cout<<left<<setw(35)<<"School Name "<<setw(25)<<"Mascot"
			<<setw(5)<<"Year Founded"<<endl;

		cout<<setfill('-')<<setw(72)<<'-'<<endl<<setfill(' ');

		//loop through and display list elements in numbered rows
		do
		{
			x++;

			cout<<x<<". "<<setw(32)<<curptr->sname<<setw(25)
				<<curptr->mascot<<setw(10)<<curptr->fyear<<endl;

			curptr = curptr->next;

		} while(curptr != NULL);
	}
	else
	{
		cout<<"There are no schools to print!"<<endl<<endl;
	}

	menu();
}

highschool* search(string look4, int &pos)
{
	curptr = headptr;

	do {
		if (curptr->sname == look4)
			return curptr;

		else {
			pos++;
			curptr = curptr->next;
		}
	} while (curptr != NULL);

	return NULL;		// Me - after function complete, NULL will only be returned if not found

	//don't call menu here - it is taken care of in the menu!
}

void menu()
{
	cout<<"\n\n------Welcome to my linked list of high schools!-------"
		<<"\n\nPlease enter the number of your choice\n"
		<<"1. Add schools\n2. Delete school\n3. Search for a school" 
		<<"\n4. Print all schools \n5. Exit\n\n";

	int c=0;

	string look4 = "";			//school name to use for search option

	highschool *r = NULL;		//school pointer to use for search option

	int pos = 0;				//school position on list to use for search option

	cin>>c;
	cin.ignore(80,'\n'); //ignores the new line character still sitting in input stream when the integer is read...
						//this is necessary in order to use getline properly for reading strings...

	cout << endl;

	/*while ((int(c) < 1) || (int(c) > 5)) {
		cout << "Invalid input. Try again." << endl << endl;
		cin.ignore(80, '\n');
		cin >> c;
		cin.ignore(80, '\n');
	}*/

	switch(c)
	{
		case 1:
			add();
			break;
		case 2:
			remove();
			break;
		case 3:							// Student needs to add some statements for case 3
			//if the list is empty
			if (headptr == NULL)
				cout << "\nThe list is empty!  Nothing to search for!" << endl << endl;

			//else ... perform the search
			else
			{
				do
				{
					cout<<"What school are you looking for?  ";
					getline(cin,look4);

				} while(look4=="");

				r = search(look4, pos);

				if (r != NULL)
				{
					cout << "School found at position: " << pos+1 << endl;
					cout<< pos+1 <<". " << setw(33) << r->sname << setw(25)
						<< r->mascot << setw(5)<< r->fyear << endl;
				}
				else
					cout<<"Sorry - that school is not on the list!"<<endl;

				pos = 0;
			}

			menu();
			break;
		case 4:
			printall();
			break;
		case 5:
			break;
		default:
			cout<<"Error!  Try again...\n\n";
			menu();
	}					// Me - don't need ; at end like on website
}