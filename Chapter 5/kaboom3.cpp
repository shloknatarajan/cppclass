#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>

using namespace std;

// Function prototypes
void kaboom();
void averages();
void draw_rectangles();
int menu();


void kaboom()
{
    int count_down=10;

	while(count_down > 0)
		{
			cout << count_down << "...";
			count_down--;
		}

}


void averages()
{
	double num=0, sum=0, n=0;
	char ch=' ';


	cout << "Enter a list of numbers to average." << endl;
	cout << "Type 'q' or 'Q' to mark the end of the list." << endl << endl;
	
	cin.get(ch);

	while((ch != 'q') && (ch != 'Q'))
		{
			if(isdigit(ch) || ch =='.') // if char is #
			{
				cin.putback(ch);
					
				cin >> num;	// reads back out as double

				sum += num;
				n++;
			}
			cin.get(ch); // get next char
		}
	cout << "\nThe average is " << sum/n << endl;

	menu();
}


void draw_rectangle()
{
	int height, width, width_counter;

	cout << "Enter height: ";
	cin >> height;
	cout << "Enter width: ";
	cin >> width;
	cout << endl;

	width_counter = width;

	while(height)
		{
			while(width_counter)
				{
					cout << "* ";
					width_counter--;
				}
			width_counter = width;
			cout << endl;
			height -= 1;
		}
}


int menu()
{
	char choice;

	cout << "\n----------Loop Practice (choose a number)----------" << endl;
	cout << "1. Kaboom" << endl;
	cout << "2. Averages" << endl;
	cout << "3. Draw Rectangles" << endl;
	cout << "4. Clear Screen/Restart" << endl;
	cout << "5. Quit" << endl << endl;

	
	cout << "Enter a menu option number: ";
	cin >> choice;
	cout << endl;
	switch(choice)
	{
	case '1':
        {
	       kaboom();
	       menu();
	       break;
	    }
	case '2':
	    {
	       averages();
		   menu();
	       break;
	    }
	case '3':
	    {
	       draw_rectangle();
			menu();
	       break;
	    }
	case '4':
		{
			system("CLS");
			menu();
			break;
		}
	case '5':
	    {
	       cout << "Goodbye!" << endl;
           exit(EXIT_SUCCESS);
	    }
	default:
	    cout << "Please enter a valid option." << endl;
	    menu();
	    break;
	}

	return 0;
}


int main()
{
	menu();

	cout << endl;
	return 0;
}