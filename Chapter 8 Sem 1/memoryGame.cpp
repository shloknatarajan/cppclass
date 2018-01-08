#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <time.h>


using namespace std;

char cardsDown[4][4]; //array of stars, changes when user picks a card
char cardsUp[4][4];  //array of special characters
int randArray[8];	 // used by setCards()
bool over=false;  //whether or not game is over(all matches have been found) 
int moves=0;  //number of moves 
int clear=0;  //keeps track of the number of matches made

void printOut(char [4][4]);  //print out cardsDown each time
void move();  //asks user which cards to pick
	//keeps track of matches and moves
void setCards();  //initializes cards (partially done for you)

int main()
{
	
	srand((unsigned)time(NULL));

	//initialize game(call setCards and set over, moves, and clear to default values)

	setCards();
	moves = 0;
	clear = 0;

	//keep printing out cards and making a move until all matches are found

	while (clear < 8)
		{
			printOut(cardsDown);
			move();
		}
		
	//Tell the user how many moves they won in

	cout << "\nYou won in " << moves << " moves. Congrats!" << endl << endl;

	return 0;
}


void printOut(char a[4][4])
{
	//Clear the screen and print -------Memory-------

	system("CLS");

	cout << " -----Memory-----" << endl;

	//print column numbers

	cout << "     0 1 2 3" << endl;

	//print row numbers and each element of cardsDown (a nested loop)

	for (int i=0; i < 4; i++)
		{
			cout << "   " << i << ' ';

			for (int j=0; j < 4; j++)
					cout << a[i][j] << ' ';

			cout << endl;
		}

	//skip a couple lines

}

void move()
{
	int row1, col1, row2, col2;
	bool looper = 0;
	
	//Ask user for row and column of first card to pick-error trap to make sure the card exists (use a while loop!)
    
	do{	
		cout << " Enter Row 1: ";
		cin >> row1;
		
		while ((row1 < 0) || (row1 > 3))
			{
			    cout << " Row must be between 0 and 4." << endl;
			    cout << " Enter Row 1: ";
			    cin >> row1;
			}
		
		
		cout << " Enter Col 1: ";
		cin >> col1;
		
		while ((row1 < 0) || (row1 > 3))
			{
			    cout << " Column must be between 0 and 4." << endl;
			    cout << " Enter Column 1: ";
			    cin >> col1;
			}

		if (cardsDown[row1][col1] != '*')
			{
				cout << " You already solved that one. Pick another!" << endl;
				looper = 1;
			}

		else
			looper = 0;

	} while (looper);

	looper = 0;

	//set the correct element of b (the row and column the user chose) to the corresponding element of cardsUp and print out b 

	cout << " Character:  " << cardsUp[row1][col1] << endl << endl;

	//Ask user for row and column of second card to pick-error trap to make sure the card exists and isn't the same as the first card (use a while loop!)

	do{	
		cout << " Enter Row 2: ";
		cin >> row2;
		
		while ((row2 < 0) || (row2 > 3))
			{
				cout << " Row must be between 0 and 4." << endl;
				cout << " Enter Row 2: ";
				cin >> row1;
			}
		
		
		cout << " Enter Col 2: ";
		cin >> col2;
		
		while ((row2 < 0) || (row2 > 3))
			{
				cout << " Column must be between 0 and 4." << endl;
				cout << " Enter Col 2: ";
				cin >> col2;
			}

		if ((cardsDown[row2][col2] != '*') || ((row1 == row2) && (col1 == col2)))
			{
				cout << " You already solved that one. Pick another!" << endl;
				looper = 1;
			}

		else
			looper = 0;

	} while (looper);

	//set the correct element of b (the row and column the user chose) to the corresponding element of cardsUp and print out b

	cout << " Character:  " << cardsUp[row2][col2] << endl << endl;

	//increase the number of moves

	moves++;

	//if both cards match, print "You got a match!", set the corresponding elements to spaces, increase clear by 2, call the Sleep function

	if (cardsUp[row1][col1] == cardsUp[row2][col2])
		{
			cout << "You got a match!" << endl;
			clear++;

			cardsDown[row1][col1] = cardsUp[row1][col1];
			cardsDown[row2][col2] = cardsUp[row2][col2];
		}

	//if the cards don't match, print "No match!", set the corresponding elements to *'s and call the Sleep function

	else
		cout << "No match!" << endl;

	Sleep(1500);

	//if clear=16, set over to true
}

void setCards()
{
	//this part fills cardsUp with characters
	//cardsUp part is done for you-don't touch it!!
	int randNum=0;
	for(int r=0; r<8; r++)
		randArray[r]=0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{	
				do
				{
					randNum=rand()%8;
				}while(randArray[randNum]>1);
			
			cardsUp[i][j]=char(randNum+224);
			randArray[randNum]++;

		}
	}

	//fill cardsDown with *'s (nested loop)

	for (int i=0; i < 4; i++)
			for (int j=0; j < 4; j++)
					cardsDown[i][j] = '*';
}