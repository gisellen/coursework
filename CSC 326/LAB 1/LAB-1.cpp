#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
/*************************************
LAB 1
CSC 326
PURPOSE: CALCULATING STUDENTS GRADES BASED ON AVERAGE
*************************************/
struct SG {
	float arraySG[10];
	string name;
	char LG;
};

//prototypes
char checkGrade(float);
float average(float);
void output(SG, float);

int main()
{
	// declaring arrays
	float sum = 0, averageNum;
	SG student[3];
	ifstream inFile;
	inFile.open("Data.txt");

	if (inFile.fail()) {
		cout << "This file cannot be opened." << endl;
		exit(1);
	}

	//initializing variables for each student object
	for (int i = 0; i < 3; i++) {
		inFile >> student[i].name; // put students name from file into object
		for (int j = 0; j < 10; j++) {
			inFile >> student[i].arraySG[j]; // put students grade in obj array
			sum = sum + student[i].arraySG[j]; // get sum to calculate average
		}
		averageNum = average(sum);
		student[i].LG = checkGrade(average(sum));
		output(student[i], averageNum);

		//resetting variables for the next student to be inputted
		averageNum = 0;
		sum = 0;
	}
inFile.close();
	return 0; //end of main
}

float average(float num) { // function will calculate the average from the grades
	num = num / 10;
	return num;  // brings back the average number to main
}

char checkGrade(float grade) { // function will check the grade of the student and determine letter grade and return a letter based on the average given
	if (grade == 0) {
		return 'W';
	}
	if (grade <= 50) {
		return 'F';
	}
	if (grade > 50 && grade <= 60) {
		return 'D';
	}
	if (grade > 60 && grade <= 70) {
		return 'C';
	}
	if (grade > 70 && grade <= 88) {
		return 'B';
	}
	if (grade > 88 && grade <= 100) {
		return 'A';
	}
}

void output(SG student, float avr) { // function will output a singular student
	cout << "Name: " << student.name << endl;

	cout << "Grades: ";
	for (int k = 0; k < 10; k++) {
		cout << student.arraySG[k] << " ";
	}
	cout << endl;
	cout << "Average: " << avr << endl;
	cout << "Grade: " << student.LG << endl;
	cout << "\n" << endl; // end of individual student output
}

/*
TEXT FILE
==========
Giselle 95 48 58 0 34 69.5 43 54 76.2 98
Johnny 86 98 56.4 86 98 67 97 85 85 86
Ren 47 86.5 86 74 78 64.4 76 74 0 54


OUTPUT
==========
Name: Giselle
Grades: 95 48 58 0 34 69.5 43 54 76.2 98
Average: 57.57
Grade: D

Name: Johnny
Grades: 86 98 56.4 86 98 67 97 85 85 86
Average: 84.44
Grade: B

Name: Ren
Grades: 47 86.5 86 74 78 64.4 76 74 0 54
Average: 63.99
Grade: C
*/