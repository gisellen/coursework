/* 
LAB 6B
NOV 15. 2018
PURPOSE: TO CREATE A MENU DRIVEN PROGRAM TO SELL COFFEE AND SHOW THE STATISTICS OF THE ORDERS*/

#include <iostream>
#include <iomanip>
using namespace std;

/*declaring the parameters*/
void howto();
int sell(int&, int&, int&);
void eachcup(int, int, int);
void totalcoffee(int, int, int);
int totalmoney(int, int, int);
int main()
{
	/*declaring varibales*/
	char select = '0'; //for the user to navigate through the program
	int small, medium, large; //number of cups that are going to be sold
	int totalcups;
	int totalsmall, totalmedium, totallarge; //the total of each cups

											 /*initializing variables to avoid error*/
	small = 0;
	medium = 0;
	large = 0;
	totalsmall = 0;
	totalmedium = 0;
	totallarge = 0;
	totalcups = 0;

	/*used a while loop so the program will operate until the user is finished*/
	while (select == '0')
	{
		cout << "SELECT OPTION:" << endl;
		cout << "1. HOW TO USE\n" << "2. SELL\n" << "3. EACH COFFEE SOLD\n" << "4. TOTAL COFFEE SOLD\n" << "5. TOTAL MONEY\n" << "6. EXIT" << endl;
		cout << "Which option would you like to choose?" << endl;
		cin >> select; //user select what they desire


					   /*algorithms within the options*/
		if (select == '1') //how to instructions descibing the function of each options of the program
		{
			howto();

			cout << " Enter 0 to go back to the main menu or choose another option from the main menu: ";
			cin >> select;
		}

		if (select == '2') //user inputs the order here
		{
			sell(small, medium, large);

			/*adds the total amount of cups for the parameter function [eachcup]*/
			totalsmall += small;
			totalmedium += medium;
			totallarge += large;

			cout << " Enter 0 to go back to the main menu or choose another option from the main menu: ";
			cin >> select;

		}

		if (select == '3') //shows total number of each cup sold
		{
			eachcup(totalsmall, totalmedium, totallarge);
			cout << " Enter 0 to go back to the main menu or choose another option from the main menu: ";
			cin >> select;
		}

		if (select == '4') //shows total amount of coffee sold
		{
			totalcoffee(totalsmall, totalmedium, totallarge);
			cout << " Enter 0 to go back to the main menu or choose another option from the main menu: ";
			cin >> select;
		}

		if (select == '5') //shows the total money made
		{
			totalmoney(totalsmall, totalmedium, totallarge);
			cout << " Enter 0 to go back to the main menu or choose another option from the main menu: ";
			cin >> select;
		}

		if (select == '6') //stops the program
		{

		}

	}



	return 0;
}
void howto()
{
	cout << setw(50) << "===HOW TO USE===" << endl;
	cout << "> CHOSE ANY OPTIONS YOU DESIRE.\n" << endl;
	cout << "> OPTION 2 IS THE CUSTOMER ORDER, IT WILL ASK YOU WHAT THE CUSTOMER WANTS AND SHOWS THE RECIEPT" << endl;
	cout << "> OPTION 3 SHOWS THE TOTAL AMOUNT OF EACH CUP SOLD DURING THE SESSION" << endl;
	cout << "> OPTION 4 SHOWS THE TOTAL NUMBER OF CUPS OVERALL SOLD DURING THE SESSION" << endl;
	cout << "> OPTION 5 SHOWS THE TOTAL MONEY MADE DURING THE SESSION" << endl;
	cout << "> OPTION 6 CLOSES THE SYSTEM" << endl;

}
int sell(int &s, int &m, int &l)
{
	/*declaring variables and initialize them*/
	char order = 'y', select = 'a';
	double s$ = 0, m$ = 0, l$ = 0;
	const double small$ = 2.75, medium$ = 2.90, large$ = 3.00;
	/*this will reset the number to 0 to avoid getting mixed up with other functions*/
	s = 0;
	m = 0;
	l = 0;

	cout << setw(50) << "===ORDERING===" << endl;
	cout << "There are 3 sizes of coffee cups: ";
	cout << "small (9oz)" << ", medium (12oz)" << ", large (15oz).\n\n" << endl;


	cout << "Select coffee size: " << endl;
	cout << "- s for small 9oz : $2.75" << endl;
	cout << "- m for medium 12oz : $2.90" << endl;
	cout << "- l for large 15oz : $3.00 \n" << endl;


	cout << "Enter amount of small coffee: ";
	cin >> s;
	cout << "Enter amount of medium coffee: ";
	cin >> m;
	cout << "Enter amount of large coffee: ";
	cin >> l;


	/*multiples the amount of cups by their base price*/
	s$ = s * small$;
	m$ = m * medium$;
	l$ = l * large$;

	cout << setw(50) << "===REVIEW===" << endl;
	cout << "ORDER:" << endl;
	cout << s << " small cup(s)" << setw(30) << setprecision(2) << fixed<< "$" << s$ << endl; //check set precision
	cout << m << " medium cup(s)" << setw(30) << setprecision(2) << fixed<<"$" << m$ << endl;
	cout << l << " large cup(s)" << setw(30) << setprecision(2) <<fixed<< "$" << l$ << "\n\n" << endl;
	cout << "The total amount is: " << s$ + m$ + l$ << endl;
	return 0;
}
void eachcup(int x, int y, int z)
{
	cout << setw(50) << "===NUMBER OF EACH CUP SOLD===" << x << endl;
	cout << "The total number of small cups sold is: " << x << endl;
	cout << "The total number of medium cups sold is: " << y << endl;
	cout << "The total number of large cups sold is: " << z << endl;

}

void totalcoffee(int x, int y, int z)
{
	cout << setw(50) << "===TOTAL NUMBER OF CUPS SOLD===" << x << endl;
	int total = 0;
	total = x + y + z; //adding all together for the total coffee sold

	cout << "The total number of coffee sold today is: " << total << endl;
}

int totalmoney(int x, int y, int z)
{
	cout << setw(50) << "===TOTAL MONEY MADE===" << endl;

	/*declaring and initializing variables*/
	const double small$ = 2.75, medium$ = 2.90, large$ = 3.00;
	double totalmoney = 0, s = 0, m = 0, l = 0;

	/*multiplying the total amount of each cup sold and the set price of each size*/
	s = small$ * x;
	m = medium$ * y;
	l = large$ * z;

	/*after multiplying, it adds each of the money to get its total*/
	totalmoney = s + m + l;

	cout << "The total money made today is: $" << setprecision(2) <<fixed<< totalmoney << endl;

	return 0;
}





