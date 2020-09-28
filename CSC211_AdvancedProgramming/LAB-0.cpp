//*******************************************************************
//*  Programmer: Giselle Ng                                         *
//*  CSC 211 – xxxx                Instructor: Frederick E. Johnson *
//*  Date Assigned: Jan 28, 2019   Date Completed: Jan 30, 2019     *
//*                            Lab 0A                               *
//*                                                                 *
//*  Write a program that allows the user to enter five numbers and *
//*  then computes and displays BOTH the sum and product in the     *
//*  exact format as illustrated in the example below.              *
//*                                                                 *
//*  EXAMPLE:  If the user entered 2 3 100 10 5                     *
//*                                                                 *
//*            then the output would be                             *
//*                                                                 *
//*              120 = 2 + 3 + 100 + 10 + 5                         *
//*              30000 = 2 X 3 X 100 X 10 X 5                       *
//*                                                                 *
//*******************************************************************

#include <iostream>
using namespace std;

int main()
{
	int num[5], sum = 0, product = 1; // setting variables 

	for (int x = 0; x < 5; x++)
	{
		cin >> num[x]; //used arrays to store the numbers that was inputted

		//calculation
		sum = sum + num[x];
		product = product * num[x];
	}	

	/* outputting sum and product while using the for loop to output the array as well to show the numbers being multiplied and added*/

	cout << sum << " = ";
	for (int x = 0; x < 5; x++)
	{
		cout << num[x];
		if (x < 4)
			cout << " + ";
	}
	cout << endl;

	cout << product << " = ";
	for (int x = 0; x < 5; x++)
	{
		cout << num[x];
		if (x < 4)
			cout << " X ";
	}
	cout << endl;
	return 0;
} // end of main