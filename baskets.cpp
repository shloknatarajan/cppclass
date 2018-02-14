// Example 1: Program to demonstrate how to create structs and use an array of structs. 
// The SYSTEMTIME struct is also used to get the windows time information 

/* structs1.cpp :
	This program will show you structs and arrays of structs
*/

// Ch. 10 Example 1

// Purpose - uses a couple of structs!

#include <iostream>
#include <iomanip>		//output money with 2 decimal places, rounded
#include <windows.h>	//for SYSTEMTIME
#include <string>		//month names
#include <ctime>		//seeding random number generator

using namespace std;

//*************************************************

struct Basket
{
	int apples;
	int tomatoes;
	int candyBars;
	double totalPrice;
	char coupon;
};
//*************************************************

struct Prices
{
	string moName;  //name of the month
	double a;   //apple price
	double t;   //tomato price
	double c;   //candy bar price
};
//*************************************************

Prices monthlyPrices[12]= {{"January",1.29,2.33,.85},
							{"February",1.25,2.30,.85},
							{"March",1.15,2.27,.85},
							{"April",.99,2.01,.85},
							{"May",.90,1.65,.85},
							{"June",.90,1.65,.85},
							{"July",.90,1.65,.85},
							{"August",.99,2.01,.85},
							{"September",1.15,2.27,.85},
							{"October",1.15,2.27,.85},
							{"November",1.15,2.27,.85},
							{"December",1.25,2.30,.85}};

double computeTax(Basket);
void getandprintPrices(int);
double getDisc(Basket b);
double getSubTotal(Basket);
void calcBill(Basket &);
void printBill(Basket);
void userBasket(Basket &);

double aPrice, tPrice, cPrice;

//*************************************************

int main()
{
	//get current month from the system
	SYSTEMTIME st;   //SYSTEMTIME is a struct datatype!!!!
	GetSystemTime(&st);  //changes st to hold the current time information
	int mo = st.wMonth;   //wMonth is an integer, so mo ends up being 1 for Jan, 2 for Feb, etc...

	Basket customer1;   //make a basket for the customer

	getandprintPrices(mo-1);   //print out this months prices from the array of Prices
							   // Month data in index position mo-1

	userBasket(customer1);		// get user's order and coupon

	calcBill(customer1);

	cout<<"\n\nYOUR BASKET AND BILL:"<<endl;
	printBill(customer1);

	return 0;
}
//*************************************************

double computeTax(Basket b)
{
	return 0.06 * getSubTotal(b);
}
//*************************************************

void userBasket(Basket &b)
{
	cout << "Enter number of apples: ";
	cin >> b.apples;
	cout << "Enter number of tomatoes: ";
	cin >> b.tomatoes ;
	cout << "Enter number of candy bars: ";
	cin >> b.candyBars;
	cout << "What letter is on your coupon ('X' if no coupon): ";
	cin >> b.coupon;

}
//*************************************************

void getandprintPrices(int x)
{
		aPrice = monthlyPrices[x].a;
		tPrice = monthlyPrices[x].t;
		cPrice = monthlyPrices[x].c;

		cout << setprecision(2)<<fixed<<showpoint
		<<setfill('_')<<setw(80)<<"_"<<endl<<endl
		<< "Prices for "<<monthlyPrices[x].moName <<": \n"
		<< "Apples: $"<<monthlyPrices[x].a
		<<" each   Tomatoes: $"<<monthlyPrices[x].t
		<<" each   Candy Bars: $"<<monthlyPrices[x].c<<endl
		<<setfill('_')<<setw(80)<<"_"<<endl<<endl;

}
//*************************************************

void calcBill(Basket &b)
{
	b.totalPrice=getSubTotal(b)-getDisc(b)+computeTax(b);
}
//*************************************************

double getSubTotal(Basket b)
{
	return b.apples*aPrice +b.candyBars*cPrice + b.tomatoes*tPrice;
}
//*************************************************

double getDisc(Basket b)
{
	double disc=0;

	switch(toupper(b.coupon))
	{
	case 'A':
		disc=1;
		break;
	case 'B':
		disc=2;
		break;
	case 'C':
		disc=3;
		break;
	default:
		disc=0;
		break;
	}
	double sub = getSubTotal(b);
	if(sub-disc<0)
		disc=sub;
	return disc;
}
//*************************************************

void printBill(Basket b)
{
cout<<setfill('-')<<setw(50)<<"-"<<endl
		<<"Apples: "<<b.apples<<"  Tomatoes: "<<b.tomatoes<<"   Candy Bars: "<<b.candyBars<<endl
		<<setfill('-')<<setw(50)<<"-"<<endl
		<<"SubTotal: $"<<getSubTotal(b)<<endl
		<<"Discount: $"<<getDisc(b)<<"    Coupon: "<<(char)toupper(b.coupon) <<endl
		<<"Tax: $"<<computeTax(b)<<endl
		<<setfill('=')<<setw(50)<<"="<<endl
		<<"Total cost: $"<<b.totalPrice <<endl
		<<setfill('-')<<setw(50)<<"-"<<endl;
}


