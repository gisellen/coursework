//  LAB 4B
//  OCT. 18 2018
//  PURPOSE:  TO SHOW THE CHANGE IN POPULATION OVER THE YEARS. 

#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
	/*INITIALIZE VARIABLES*/
	int pop = 1500;
	int origpop = 1500;
	int year=1, newbirths, killed;
	/*CREATING THE TABLE*/
	cout << setw(20) << fixed << left << "YEAR"; //the setw will make columns more organized.
	cout << setw(20) << fixed << left << "ALIVE AT START";
	cout << setw(20) << fixed << left << "NEW BIRTHS";
	cout << setw(20) << fixed << left << "KILLED";
	cout << setw(20) << fixed << left << "ALIVE AT END" << endl;
	/*CALCULATION*/
	while (pop>165) //New stats will be shown year after year
	{
		newbirths = pop * 0.05; //# of new births


		cout << setw(20) << year; //lining up the numbers under their own columns
		cout << setw(20) << origpop;
		cout << setw(20) << newbirths;
		pop = pop + newbirths;
			killed = pop * 0.17; //# of deaths
		killed = pop * 0.17; //# of deaths
		cout << setw(20) << killed;
			pop = pop - killed; //new population
		cout << setw(20) << pop;
		cout << "\n" << endl;
		year++;
		origpop = pop; // It will show the population before new births and killed each year.
	}

	return 0;
}






