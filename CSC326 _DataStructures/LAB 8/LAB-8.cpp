/*
csc 326  
lab 8 

PURPOSE
This lab will ake use of the pointers and how it can work with dynamic storage allocation.  It will use dynamic storage allocation
to store a set of numbers in a pointer array, and will sort the array if it's unsorted.

=== input ===
34 52 3 12 74 74 34 74 74 74 74 74 74

=== output ===
how many grades are you inputting?
5
ORIGINAL ARRAY: 34, 52, 3, 12, 74
SORTED ARRAY: 3, 12, 34, 52, 74

*/

#include <new>  
#include <iostream>  
#include <fstream>  
#include <iomanip>  
using namespace std;
int main()
{
	//declaring variables 
	ifstream infile;
	int* p, *p2;
	int i, k, j, l, count = 0; // variables to be used in loops
	int temp, high;
	infile.open("Text.txt");
	if (infile.fail()) {
		cout << "This file cannot be opened." << endl;
	}
	cout << "how many grades are you inputting?" << endl;
	cin >> i;
	p = new int[i];

	//reading the file
	for (k = 0; k < i; k++) {
		infile >> p[k];
	}

	//outputting original array
	cout << "ORIGINAL ARRAY: ";
	for (j = 0; j < i; j++) {
		cout << p[j];
		if (j != i - 1) // avoids putting a comma after the last number
			cout << ", ";
	}

	//sorting
	for (l = 0; l < i; l++) {
		for (k = 0; k < i; k++) {
			if (p[l] < p[k]) {
				temp = p[l];
				p[l] = p[k];
				p[k] = temp;
			}
		}
	}

	//outputting sorted array
	cout << "\nSORTED ARRAY: ";
	for (j = 0; j < i; j++) {
		cout << p[j];
		if (j != i - 1)
			cout << ", ";
	}
	cout << endl;
	p2 = new int[i];
	int count2 = 0;
	int count3 = 0;
	//finding duplicates
	for (l = 0; l < i; l++) {
		while (p[l] == p[l + 1]) {
			count++;
			l++;
			count3++;
		}
		if (count >= 1) {
			cout << "\nThere are " << count + 1 << " " << p[l] << "'s"<< endl;
			count = 0;
			p2[count2] = p[l];
			count2++;
		}
		else {
			count = 0;
			p2[count2] = p[l];
			count2++;
		}
	}

	//outputting duplicated sort 
	cout << "\nDUPE SORTED ARRAY: " << endl;
	for (j = 0; j < i - count3; j++) {
		cout << p2[j];
		if (j != i - 1)
			cout << ", ";
	}

	//delete dynamic variable
	delete p;
	delete p2;

	return 0;
}