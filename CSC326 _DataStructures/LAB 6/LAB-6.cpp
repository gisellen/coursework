/*
CSC 326
lab 6  

PURPOSE
This is a modification of lab 5.  In this lab, it will covert the hex in to decimal and back into hex again then output the hex.
The input will be the same as lab 5.
*/

#include <iostream> 
#include <fstream> 
#include <iomanip> 
#include <string> 
using namespace std;


//declaring prototypes
int calc(string); //calculates the decimal number of the hex
int convertToDec(char); //converts the hex to decimal
void DtoH(int); //converts the decimal into hex
char convertToHex(int); //this will convert decimal into its hex form

//main
int main()
{
	//declaring and initializing variables
	int sum;
	ifstream infile;
	infile.open("Text.txt");
	if (infile.fail()) {
		cout << "This file cannot be opened." << endl;
	}
	string hex;
	infile >> hex;

	//output
	cout << "The original hex is: " << hex << endl;
	sum = calc(hex);
	cout << "The decimal of this hex is: " << sum << endl;
	cout << "The Hexidecimal equivalent of this is: ";
	DtoH(sum);
}

int calc(string hex) { //calculate the decimal number of the hex
	int n = hex.length();
	int i, sum = 0;
	int b = 0;
	for (i = n - 1; i >= 0; i--) {
		sum = sum + (pow(16, i)*convertToDec(hex[b]));
		b++;
	}
	return sum;
}
int convertToDec(char a) { //converts the hex to decimal
	switch (a) {
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case 'A':
		return 10;
		break;
	case 'B':
		return 11;
		break;
	case 'C':
		return 12;
		break;
	case 'D':
		return 13;
		break;
	case 'E':
		return 14;
		break;
	case 'F':
		return 15;
		break;
	}

}
char convertToHex(int a) { //converts the decimal to hex
	switch (a) {
	case 0:
		return '0';
		break;
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	case 10:
		return 'A';
		break;
	case 11:
		return 'B';
		break;
	case 12:
		return 'C';
		break;
	case 13:
		return 'D';
		break;
	case 14:
		return 'E';
		break;
	case 15:
		return 'F';
		break;
	}
}

void DtoH(int sum1) { //combines the decimal to its full hex form
	int remainder;
	remainder = sum1 % 16;
	sum1 = sum1 / 16;
	if (sum1 != 0) {
		DtoH(sum1);
	}
	cout << convertToHex(remainder);
}