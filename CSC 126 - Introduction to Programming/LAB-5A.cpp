/*
	LAB 5
		OCT. 28 2018
  PURPOSE:  TO DETERMINE THE FORTUNE OF THE USER BASED ON THEIR INPUT*/

#include <iomanip>
#include <iostream>
using namespace std;

void school(int);
void love(int);
void finance(int);
int main()
{
	int luckyNum,topic;

	cout << "Type in your lucky number: ";
	cin >> luckyNum;
	cout << "What life topic would you like to choose?\n" <<"Choose between school, love, or finance.\n"<<"Type in 1 for school, 2 for love, or 3 for finance"<< endl;
	cin >> topic;

	if (topic == 1)
		school(luckyNum);
	else if (topic == 2)
		love(luckyNum);
	else if (topic == 3)
		finance(luckyNum);
	return 0;
}

void school(int lucky)
{
	srand(lucky);
	switch (lucky % 5)
	{
	case 0:
		cout << "You are going to pass your next test!" << endl;
		break;
	case 1:
		cout << "You are going to have a high GPA";
		break;
	case 2:
		cout << "Class is cancelled tomorrow";
		break;
	case 3:
		cout << "You're going to lose one of your homeworks";
		break;
	case 4:
		cout << "You're going to graduate!";
		break;
	}
}

void love(int lucky)
{
	srand(lucky);
	switch (lucky % 5)
	{
	case 0:
		cout << "Your next lover will be your forever." << endl;
		break;
	case 1:
		cout << "You're going to get married at " << rand();
		break;
	case 2:
		cout << "You will never have a significant other.";
		break;
	case 3:
		cout << "Your next lover is closer than you think.";
		break;
	case 4:
		cout << "You'll have many lovers, but still be alone.";
		break;
	}
}

void finance(int lucky)
{
	srand(lucky);
	switch (lucky % 5)
	{
	case 0:
		cout << "Money is coming along your way" << endl;
		break;
	case 1:
		cout << "Be careful with your money.";
		break;
	case 2:
		cout << "Spend your money wisely.";
		break;
	case 3:
		cout << "You will recieve a raise on your next paycheck.";
		break;
	case 4:
		cout << "You will soon win the lottery.";
		break;
	}
}

