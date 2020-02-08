/*
LAB 4D
OCT. 28 2018
PURPOSE:  TO DETERMINE HOW MANY CANNIBALS WILL BE CAUGHT AND HOW MANY MISSIONARIES WILL BE SAVED AFTER THE 12 HOUR INTERVAL.*/

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	//declaring variables
	int hour = 0, tarzan = 80;
	double cannibals = 30, missionaries = 10;
	double rate = 0, temp = 0;

	//setting the table
	cout << setw(30) << left << "END OF HOUR";
	cout << setw(30) << left << "MISSIONARIES LEFT";
	cout << setw(30) << left << "CANNIBALS EATING";
	cout << setw(30) << left << "TARZAN DISTANCE";
	cout << endl;

	for (hour = 0; hour <= 12; hour++)
	{
		/*rate is how much the missionary has been consumed*/
		rate = (cannibals / 30);
		//rate is the amount that the cannibal consumed.
		temp += rate; //adding the rates after its been subtracted from one whole missionary and a cannibal has left.

		if (temp < 1)
		{
			if (hour <= 3) //calculating tarzan distance
				tarzan = tarzan - 7;
			else if (hour >= 3)
				tarzan = tarzan - 4;

			cout << setw(30) << left << hour;
			cout << setw(30) << left << missionaries;
			cout << setw(30) << left << cannibals;
			cout << setw(30) << left << tarzan;
			cout << endl;
		}
		else if (temp >= 1)
		{
			if (hour <= 3) //calculating tarzan distance
				tarzan = tarzan - 7;
			else if (hour >= 3)
				tarzan = tarzan - 4;

			cout << setw(30) << left << hour;
			cout << setw(30) << left << missionaries;
			cout << setw(30) << left << cannibals;
			cout << setw(30) << left << tarzan;
			cout << endl;
			/*Subtract missionaries and cannibials after it has been equal or over 1*/
			missionaries = missionaries - 1;
			cannibals = cannibals - 1;
			temp -= 1;
		}


	}

	return 0;
}


