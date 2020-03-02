//OCT. 1ST 2018
//LAB #3
//PURPOSE: TO CALCULATE THE NUMBER OF DAYS SINCE JANUARY 1 OF THAT YEAR USING SWITCH STATEMENT

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int day, month, year, total; //declaring variables

	cout << "Type the month" << endl;
	cin >> month; //month gets inputted
	cout << "Type the day" << endl;
	cin >> day; //day gets inputted
	cout << "Type the year" << endl;
	cin >> year; // year gets inputted
	cout << "\n\n" << endl;
	cout << "You inputted the date: " << month << "/" << day << "/" << year << "." << endl; //DATE INPUTTED
	cout << "\n\n" << endl;

	//adding the total days for each month before the leap year calculation
	switch (month)
	{
	case 1:
		total = day;
		break;
	case 2:
		total = 31 + day;
		break;
	case 3:
		total = 31 + 28 + day;
		break;
	case 4:
		total = 31 + 28 + 31 + day;
		break;
	case 5:
		total = 31 + 28 + 31 + 30 + day;
		break;
	case 6:
		total = 31 + 28 + 31 + 30 + 31 + day;
		break;
	case 7:
		total = 31 + 28 + 31 + 30 + 31 + 30 + day;
		break;
	case 8:
		total = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
		break;
	case 9:
		total = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
		break;
	case 10:
		total = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
		break;
	case 11:
		total = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
		break;
	case 12:
		total = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
			break;
	default:
		cout << "That is not a valid month." << endl;
	}

	cout << "-------------------------------------" << endl;
	if ((year % 400 == 0) || (year % 4 == 0)) //calculating whether or not it is a leap year or not
		if (year % 100 != 0) //calculating if its not evenly divisable by 100
		{
			total = total + 1;
			cout << "This year is a leap year!" << endl; //if its true it will output this
		}
		else
			cout << "This is not leap year!" << endl;
	else
		cout << "This is not a leap year!" << endl; //if its not true it will output this
	cout << "-------------------------------------\n\n" << endl;
	cout << total << " has passed since January 1st of " << year << endl;


	cout << endl;
	return 0;
}




