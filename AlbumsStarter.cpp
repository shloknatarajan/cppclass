#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//*********************************************

struct album
{
	string group;
	string name;	// name of album
	string label;
	int year;
	double price;
};
//*********************************************

vector <album> myCollection;

//*********************************************

void menu();
void initialize(vector <album> &);		// copy file contents to myCollection vector
void print(vector <album>);
vector <album> firstN(int, vector <album>); //gets first n elements and puts them in a new vector


// add a album to myCollection vector - YOU COMPLETE
void addOne();		

// copy myCollection vector to the file - YOU COMPLETE
void updateFile();					

// brings up a menu--the user can choose the search criteria
// puts results of search into a new vector
// YOU COMPLETE
vector <album> search(vector <album>);		

//*********************************************

int main()
{
	initialize(myCollection);
	return 0;
}
//*********************************************

void menu()
{
	char choice;
	int n = 0;

	cout << "1. Add an album\n"
		<< "2. Print my albums\n"
		<< "3. Print first n albums in database\n"
		<< "4. Search the database\n"
		<< "5. Exit\n";
	cin >> choice;
	cin.ignore(80, '\n');

	vector <album> subList; //for choice 3
	vector <album> result;  //for choice 4

	switch (choice)
	{
	case '1':
		//addOne();
		//updateFile();
		initialize(myCollection);
		break;

	case '2':
		print(myCollection);
		break;

	case '3':
		cout << "How many albums do you want to get?";
		cin >> n;
		subList = firstN(n, myCollection);
		print(subList);
		break;

	case '4':
		//result=search(myCollection);
		print(result);
		break;

	case '5':
		cout << "See ya!" << endl << endl;
		break;

	default:
		cout << "ERROR - Try again!";
		menu();
	}
}
//*********************************************

void initialize(vector <album> &v)
{
	album item;

	ifstream fin;
	fin.open("albums.txt");

	v.resize(0);

	while (!fin.eof())
	{
		getline(fin, item.group);
		getline(fin, item.name);
		getline(fin, item.label);

		fin >> item.year;
		fin >> item.price;

		fin.ignore(80, '\n');
		fin.ignore(80, '\n');

		if (item.group != "")
		{
			v.resize(v.size() + 1);

			v[v.size() - 1] = item;				// puts whole item structure into vector
		}
	}

	fin.close();

	cout << "Loaded " << v.size() << " albums into the database...\n";

	menu();
}
//*********************************************

void print(vector <album> v)
{
	cout << "\n\nYOUR COLLECTION" << endl;

	cout << setprecision(2) << fixed << showpoint;
	cout << setfill('-') << setw(80) << "-" << endl;
	cout << setfill(' ');

	for (int i = 0; i<v.size(); i++)
	{
		cout << setw(20) << v[i].group << setw(20) << v[i].name
			<< setw(20) << v[i].label << setw(7) << v[i].year
			<< setw(7) << "$" << v[i].price << endl;
	}

	cout << endl << endl;

	menu();
}
//*********************************************

vector <album> firstN(int n, vector <album> v)
{
	vector <album> r(n);

	if (n > v.size())
	{
		r.resize(v.size());
	}

	for (int i = 0; i<r.size(); i++)
	{
		r[i] = v[i];
	}

	return r;
}

