// OCT. 15, 2018
//LAB 4A
//PURPOSE: TO DETERMINE THE FACTORIAL OF ANY GIVEN NUMBER

#include <iostream>
using namespace std;


int main()
{
	int n, total=1,n1;
	cout << "What is your value of \"n\":";
	cin >> n;
	n1 = n;

	if (n == 0);
		total = 1;

	while (n < 0)
	{
		cout << "Sorry, you cannot determine the factorial of a negative number.  Please input a number again: ";
		cin >> n;
		n1 = n;
	}

	while (n > 1)
	{
	
		total = total * n;
			n = n - 1;
	}
	cout << n1 << "!" << " = " << total << endl;
	return 0;
}


