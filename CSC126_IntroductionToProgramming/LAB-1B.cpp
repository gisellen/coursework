// LAB 1B
// 09/17/2018
// Purpose: to calculate the interest of a user

#include <iostream>
using namespace std;

int main()
{
	int invest, years;
	double Interest, percentage;

	cout << "How much do you want to invest?" << endl;
			cin >> invest;
			cout << "\n";
	cout << "How many years?" << endl;
			cin >> years;
			cout << "\n";
	cout << "What percentage is the interest?" << endl;
			cin >> percentage;
			cout << "\n";
			cout << "******************************************\n\n";
			cout << invest << " invested for " << years << " at " << percentage << "% interest.\n\n" << endl;
		
			percentage = percentage / 100;
			Interest = invest*(pow((1.0 + percentage), years));
			
			cout << "******************************************\n\n";
	cout << "Here is your interest rate:\n"<< Interest << endl;
	return 0;
}


