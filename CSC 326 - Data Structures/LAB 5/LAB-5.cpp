/*

csc 326
lab 5:  
Coverting hex into decimal and back into hex again.  The input (Data.txt) consists of any Hex
number that will be converted.  The output will show the decimal version of the hex and show the hex
again after its converted from the decimal.  This conversion is more visable within the code itself.

*/

//preprocessors
#include <iostream> 
#include <fstream> 
#include <iomanip> 
#include <string> 
using namespace std;


//declaring prototypes
int calc(string);
int convertToDec(char);
void DtoH(int);
char convertToHex(int);

int main()
{
    //declaring and initializing variables
	int sum;
	ifstream infile;
	infile.open("Data.txt");
	if (infile.fail()) {
		cout << "This file cannot be opened." << endl;
	}
	string hex;
   
    // inputs and outputs
	infile >> hex;
	cout << "The original hex is: " << hex << endl;
	sum = calc(hex);
	cout << "The decimal of this hex is: " << sum << endl;
	cout << "The Hex (converted back) of this is: ";
	DtoH(sum);
}

int calc(string hex) {  //this function will calclate the decimal number of the hex
	int n = hex.length();
	int i, sum = 0;
	int b = 0;
	for (i = n - 1; i >= 0; i--) {
		sum = sum + (pow(16, i)*convertToDec(hex[b]));
		b++;
	}
	return sum;
}


void DtoH(int sum) { //this function will convert deciment to hex
	int remainder[100], i = 0;
	int count = 0;
	string hex;
	while (sum != 0) {
		remainder[count] = sum % 16;
		sum = sum / 16;
		count++;
	}
	for (int a = count - 1; a >= 0; a--) {
		cout << convertToHex(remainder[a]);
	}

}


int convertToDec(char a) { //this function will calculate the decimal number based on the hex given
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

char convertToHex(int a) { //based on the decimal, this will convert the decimal to hex individualy
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
