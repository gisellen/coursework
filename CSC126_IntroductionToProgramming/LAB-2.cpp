// LAB 2
// SEPT. 22, 2018
// PURPOSE:  TO CHECK THE AMOUNT OF CHANGE THAT THE USER IS RECEIVING

#include <iomanip>
#include <iostream>
using namespace std; 

int main()
{
	int dollars, quarters, dimes, nickels, pennies, TempChange;
	double paid, change, check;
	//set variables
	
	cout << "Enter the amount of the check:" << endl;
	cin >> check;
	cout << setw(6) << setprecision(2) << fixed << showpoint <<setfill('$')<<right << check << endl;
	cout << "Enter the amount of the customer paid:" << endl;
	cin >> paid;
	cout << setw(6) << setprecision(2) << fixed << showpoint << setfill('$') << right << paid << endl;

	change = paid - check; //To find the change

	cout << "Check: $" << check << endl;
	cout << "Paid: $" << paid << endl;
	cout << "The change is $:" << change << endl;

	pennies = change * 100; //Changes to pennies 
	dollars = pennies / 100; // Find Dollars
	cout << dollars << " dollar bill(s)" << endl;
	TempChange = pennies % 100; //Remaining pennies after finding dollars

	quarters = TempChange / 25; // Find Quarters
	cout << quarters << " quarter(s)" << endl;
	TempChange = TempChange % 25; //Remaning pennies after finding quarters

	dimes = TempChange / 10; //Find dimes
	cout << dimes << " dime(s)" << endl;
	TempChange = TempChange % 10; //Remaining pennies after finding dimes

	nickels = TempChange / 5; //Find nickels
	cout << nickels << " nickel(s)" << endl;
	pennies = TempChange % 5; //Find remaining pennies

	cout << pennies << " penny(s)" << endl;

return 0;
}


