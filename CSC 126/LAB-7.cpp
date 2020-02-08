// LAB7
// NOV 21ST, 2018
// PURPOSE: TO DETERMINE HOW MANY FISH ARE LEFT EATEN. 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int totalfish = 0;
	int i;
	int bowls[35] = { 15,15,15,8,8,8,8,19,16,16,16,16,14,14,14,14,14,14,14,14,14,14,31,31,9,9,9,9,9,26,26,26,26,8,8 };

	for (i = 0; i < 6; i++)
		cout << bowls[i] << " goldfishes " << endl;
	for (i = 6; i < 13; i++)
		cout << bowls[i] << " guppies " << endl;
	for (i = 13; i < 22; i++)
		cout << bowls[i] << " angel fish " << endl;
	for (i = 22; i < 30; i++)
		cout << bowls[i] << " goldfishes " << endl;
	for (i = 30; i < 35; i++)
		cout << bowls[i] << " tiger fishes " << endl;
	
	cout << "\n" << endl;

	for (i = 0; i < 35; i++)
	{
		totalfish = totalfish + bowls[i];
	}
	cout << totalfish << " is the total amount of fish there" << endl;

	i = 0; 

	while (totalfish > 166)
	{
		i = i + 4;
	
		if (i == 35)
		{
			i = 0;
			if (bowls[i] ==0)
			{
				i = i + 4;
			}
		}
		if (i == 36)
		{
			i = 1;
			if (bowls[i] ==0)
			{
				i = i + 4;
			}
		}
		if (i == 37)
		{
			i = 2;
			if (bowls[i] ==0)
			{
				i = i + 4;
			}
		}
		if (i == 38)
		{
			i = 3;
			if (bowls[i] == 0)
			{
				i = i + 4;
			}
		}
		if (bowls[i] == 0)
		{
			i = i + 4;
		}
		bowls[i] = bowls[i] - 1;
		totalfish = totalfish - 1;

	}


	cout << "\n\n\n\n AFTER \n" << endl;

	for (i = 0; i < 6; i++)
		cout << bowls[i] << " goldfishes " << endl;
	for (i = 6; i < 13; i++)
		cout << bowls[i] << " guppies " << endl;
	for (i = 13; i < 22; i++)
		cout << bowls[i] << " angel fish " << endl;
	for (i = 22; i < 30; i++)
		cout << bowls[i] << " goldfishes " << endl;
	for (i = 30; i < 35; i++)
		cout << bowls[i] << " tiger fishes " << endl;

	cout << totalfish << " is the total amount of fish left" << endl;

	return 0;
}


