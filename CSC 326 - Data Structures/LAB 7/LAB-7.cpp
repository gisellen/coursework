/*
CSC 326
LAB 7

PURPOSE
This lab will determine the BMI and the status of the user.  The data that will be inputted will be within the class members.
The user will input the data to what they wish and the output will show all of the the users BMI based on the information given.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//setting the class
class secretType{
public:
	void setName(string);
	void setAge(int);
	void setWeight(int);
	void setHeight(double);
	string getName() const;
	int getAge() const ;
	int getWeight() const ;
	double getHeight() const ;
	string weightStatus();
private:
	string name;
	int age;
	int weight;
	double height;
};

//main
int main()
{
	//declaring variables
	secretType user;
	string name;
	int age, weight;
	double height, BMI;

	//inputting each member
	cout << "Please enter your Name: ";
	cin >> name;
	user.setName(name);
	cout << "Please enter your age: ";
	cin >> age;
	user.setAge(age);
	cout << "Please enter your weight in pounds: ";
	cin >> weight;
	user.setWeight(weight);
	cout << "Please enter your height in inches: ";
	cin >> height;
	user.setHeight(height);

	//output
	cout << user.weightStatus();
}

void secretType::setName(string StrName) { //this will set the name in the private member, Name
	name = StrName;
}

void secretType::setAge(int AgeNum) { //this will set the name in the private member, AgeNum
	age = AgeNum;
}

void secretType::setWeight(int WeightNum) { //this will set the weight in the private member, WeightNum
	weight = WeightNum;
}

void secretType::setHeight(double HeightNum) { //this will set the height in the private member, HieghtNum
	height = HeightNum;
}

string secretType::getName() const { //returns name
	return name;
}

int secretType::getAge() const { //returns age
	return age;
}

int secretType::getWeight() const { //returns weight
	return weight;
}

double secretType::getHeight() const { //returns height
	return height;
}

string secretType::weightStatus(){ //this function will output the users BMI based on the information stored in the private members
	double BMI;
	BMI = (weight * 703) / height;
	if (BMI < 18.5)
		return ("Underweight");
	else if (BMI > 18.5 && BMI < 24.9)
		return ("Normal");
	else if (BMI > 25.0 && BMI < 29.9)
		return ("Overweight");
	else if (BMI > 30)
		return ("Obese");
}