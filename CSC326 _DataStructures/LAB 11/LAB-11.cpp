/*
CSC 326
Lab 11

PURPOSE
This lab creates a hash table made from scratch.  It will also have a search function that will determine if the value inputted by the user exists in the hash table.

The input will be given numbers already inputted in a file. 
The numbers that will go through the hash function and will be stored into a linked list.
The user will then be able to input a number to search for, then a function will determine if that number exists
in the hash table or not.

The output will show the hash table when all the numbers have been stored the hash table.  Then it will output if a number, that has been
inputted by the user, exists.

*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


//first make an array of linked lists
//include funcionkey and search

//make node
//make a stack of those nodes

//global variable
const int max_num = 10;

//declaring class
class Node{
public:
	int num;
	Node* ptr;
};

//prototypes
int function(int); //function for numbers going through a hash function
int function(int, int);//function for when collision occurs
bool search(int, int); //function that will search through a 

//main
int main()
{
	//declaring and initializing variables
	Node* table, *node;
	ifstream infile;
	table = new Node[max_num];
	int num, num2=0;
	bool exists = false;
	//opening file
	infile.open("Text.txt");
	if (infile.fail()) {
		cout << "This file cannot be opened." << endl;
		exit(1);
	}

	//creating the base of the hash table
	for (int i = 0; i < max_num; i++) {
		table[i].num = i;
		table[i].ptr = nullptr;
	}
	
	//inputting numbers to go through the hash function and be stored into the hash table
	while (!infile.eof()) {
		infile >> num;
		for (int i = 0; i < max_num; i++) {
			if (table[i].num == function(num)) {
				if (table[i].ptr != NULL) {
					int count = 0;
					while (table[function(num, count)].ptr != NULL) {
						count++;
					}
					node = new Node;
					node->num = num;
					table[function(num, count)].ptr = node;
				}
				else {
					node = new Node;
					node->num = num;
					table[i].ptr = node;
				}
				i = 10;
			}
		}

	}

	//output the hash table with the numbers that has been stored
	for (int i = 0; i < max_num; i++) {
		if (table[i].ptr != nullptr) {
			cout << table[i].num << " -> " << table[i].ptr->num << endl;
		}
		else {
			cout << table[i].num << endl;
		}
	}
	
	//start the search
	cout << "Enter a value to search for: ";
	cin >> num;

	//searching algorithm
	for (int k = 0; k < max_num; k++) {
		if (table[k].ptr != NULL) {
			num2 = table[k].ptr->num;
		}
		exists = search(num, num2);
		if (exists == true) {
			k = 10;
		}
	}

	//check if it exists or not
	if (exists == true) {
		cout << "This value exists in the list." << endl;
	}
	else{
		cout << "This value does not exist on the list" << endl;
	}

}
int function(int num) { //linear probing
	return num % 10;
}
int function(int num, int basenum) { //function to avoid collision
	return (num + basenum) % 10;
}
bool search(int num, int listnum) { //search function
	if (listnum == num) {
		return true;
	}
}