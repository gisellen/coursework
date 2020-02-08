// quiz 4
// dec 10 2018
// purpose: to use fstream to calculate fees

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
double discount(double,int);
int main()
{
	//declaring variables
	ifstream inFile; 
	char student;
	int numTraveling;
	double retail, actual, total = 0;
	//open file
	inFile.open("C:\\Users\\[redacted]\\Documents\\cruise.txt");
	//if file fails to open
	if (inFile.fail())
	{
		cout << "This file cannot be opened." << endl;
		exit(1);
	}
	//header
	cout << "STUDENT";
	cout << setw(30) << "NUMBER TRAVELING";
	cout << setw(30) << "RETAIL PRICE";
	cout << setw(30) << "ACTUAL CRUISE FEE";
	cout << endl;
	cout << showpoint << setprecision(2) << fixed;


	while (!inFile.eof())
	{
		//inputting each line
		inFile >> student >> numTraveling >> retail;
		if (student == 'Y') //checking person is a student or not
			actual = discount(retail, numTraveling); //discounting price and setting it equal actual

		else if (student == 'N')
			actual = retail * numTraveling;
		total += actual; //combining total
		cout << student << setw(35) << numTraveling << setw(25) << "$" << retail << setw(25) << "$" << actual << endl;
	}

	cout << "Total actual cruise fees owed is: $" << total << endl;

	inFile.close(); //closing file

	return 0;
}
double discount(double retail, int numTraveling)
{
	double actual = 0;
	actual = retail * numTraveling;
	actual -= (actual*.10); //calculating if yes
	return actual; //returning the actual number back to main
}



