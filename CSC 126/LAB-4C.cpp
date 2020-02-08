/* 
LAB 4C
OCT. 22, 2018
PURPOSE: TO DETERMINE HOW MANY YEARS IT WILL TAKE FOR TOWN A TO BE GREATER OR EQUAL TO TOWN B. */

#include <iostream>
using namespace std;

int main()
{
	int popA, popB, growthA, growthB, years = 0, popTA, popTB;
	double rateA, rateB;
	
	/*Inputting the variables by the user*/
	cout << "Enter the current population of town A: ";
	cin >> popA;
	cout << "Enter the current population of town B: ";
	cin >> popB;
	cout << "Enter the growth rate of town A: ";
	cin >> growthA;
	cout << "Enter the growth rate of town B: ";
	cin >> growthB;
	popTA = popA;
	popTB = popB;

	/*Changing the rate into a decimal.*/
	rateA = growthA * .01;
	rateB = growthB * .01;

	if (popA > popB)
	{
		/*This is for when population of Town A is already greater than the population of Town B. */
		years = 0;
		cout << "After " << years << " years the population of town A is " << popTA;
		cout << "After " << years << " years, the population of town B is " << popTB;
	}
	else
		while (popTA <= popTB)
		{
			/*If the population of Town A is less than the population of Town B, then */
			years++;
			popTA = popA * exp(rateA*years);
			popTB = popB * exp(rateB*years);
		}

	cout << "After " << years<<" year(s) the population of town A will be greater than or equal to the population of town B.\n";
	cout << "After " << years << " years the population of town A is " << popTA<<"\n";
	cout << "After " << years << " years, the population of town B is " << popTB;
	cout << endl;
	return 0;
}
/*popTA = popA * exp((growthA*.01)*years);
			popTB = popB * exp((growthB*.01)*years);*/
/*popTA = popA * pow((1 + (growthA*.01)), years);
			popTB = popB * pow((1 + (growthB*.01)), years);*/

