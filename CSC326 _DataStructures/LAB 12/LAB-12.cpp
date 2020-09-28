/**************** 
CSC 326
LAB 12
This lab will show how stacks are visually used.  By creating different functions, I am able to set an array and linked list,  initialize them, find out if they're empty, find out
if they're full, push, pop, and find the top of the stack.  Here are the procedures that needed to be done in a list:

o  set array
o  set linked list
o  set initialize stack
o  set isemptystack
o  set isfullstack
o  set push
o  set top
o  set pop

The input will be given from a file, with a max of 10 values that will be placed in the array and linked list.

The output will show a program where the user is able to pick any choice as they wish to maniputlate the stack.  Based ont the option
that the user has chose, it will output what the user wants from both the linked list and the array.

**************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;



//global variables
const int max_num = 10;

//class for linked list
class Node {
public:
	int value;
	Node* ptr;
};

// protoypes  (comments of each function will be at the function definitions)
int *setarray();
Node *setlist();
bool isemptystack(int*);
bool isfullstack(int*);
int push(int, int* &);
int top(int*);
void pop(int*);
bool isemptystack(Node*);
bool isfullstack(Node*);
Node push(int, Node*);
int top(Node*);
Node pop(Node*);

//main function
int main()
{
	//declaring variables
	ifstream infile;
	ofstream offile;
	Node *list, *head, *tail;
	int* array1;
	int input;
	bool end = false, empty, full;

	//opening file
	infile.open("Data.txt");
	if (infile.fail()) {
		cout << "This file cannot be opened." << endl;
	}
	
	//setting the array
	array1 = setarray();
	list = setlist();
	head = list;
	tail = list;

	cout << "Linked list: " << endl;
	while (tail != NULL) {
		cout << tail->value << " ";
		tail = tail->ptr;
	}

	cout << "\n\nCurrent array: " << endl;
	for (int k = 0; k < max_num; k++) {
		cout << *(array1 + k)<< " ";
	}

	//user menu start
	cout << "\n" << endl;
	cout << "Press 1 to initizlize stack" << endl;
	cout << "Press 2 to check if the stack is empty" << endl;
	cout << "Press 3 to check if the stack is full" << endl;
	cout << "Press 4 to push a number into a stack" << endl;
	cout << "Press 5 to check the top of the stack" << endl;
	cout << "Press 6 to pop the stack" << endl;
	cout << "Press 999 to exit the program" << endl;

	//user inputs
	while (end == false) {
		cout << "input: ";
		cin >> input;
		if (input == 1) {
			delete array1;
			array1 = NULL;
			cout << "\ndeleted stack!" << endl;
			delete list;
			list = NULL;
			cout << "deleted list!\n" << endl;
		}
		else if (input == 2) {
			cout << endl;
			if (isemptystack(array1) == true) {
				cout << "The array is empty" << endl;
			}
			else {
				cout << "The array is not empty" << endl;
			}
			if (isemptystack(list) == true) {
				cout << "The list is empty" << endl;
			}
			else {
				cout << "The list is not empty" << endl;
			}
			cout << endl;
		}
		else if (input == 3) {
			cout << endl;
			if (isfullstack(array1) == true) {
				cout << "The array is full" << endl;
			}
			else {
				cout << "The array is not full" << endl;
			}

			if (isfullstack(list) == true) {
				cout << "The list is full" << endl;
			}
			else if (isfullstack(list) == false) {
				cout << "The list is not full" << endl;
			}
		}
		else if (input == 4) {
			//checking if the stack is full
			full = isfullstack(array1);
			if (full == false) {
				cout << "What number do you want to push?" << endl;
				cin >> input;
				push(input, array1);
				cout << "New linked list: " << endl;
				if (list == NULL) {
					push(input, list);
				}
				else {
					push(input, list);
				}

				cout << endl;
			}
			else {
				cout << "You cannot add anymore numbers\n" << endl;
			}
		}
		else if (input == 5) {
			cout << "The top of the array is: " << top(array1) << "\n" <<  endl;
			cout << "The top of the list is: " << top(list) << "\n" << endl;
		}
		else if (input == 6) {
			pop(array1);
			pop(list);
			cout << endl;
		}
		else if (input == 999) {
			end = true;
		}
	}
	return 0;
}

//function definitions
 
int *setarray() { //function will input the numbers based on the given numbers from the file.
	//declaring variables
	int num;
	int* arr;
	int count=0;
	ifstream file;

	file.open("Data.txt");
	if (file.fail()) 
		cout << "This file cannot be opened." << endl;
		
	//getting number from the file to store in the variable
	while (!file.eof()) {
		file >> num;
		count++;
	}
	file.close();
	arr = new int[max_num];
	count = 0;

	file.open("Data.txt");
	//inputting the numbers into the array pointer
	while (!file.eof()) {
		file >> *(arr+count);
		count++;
	}

	//if there is extra space in the array,then place a 0 on the empty spaces
	if (count != max_num-1) {
		for (int i = count; i < max_num; i++) {
			*(arr + i) = 0;
		}
	}
	
	return arr;
}

Node *setlist() { //function will create a linked list with the given numbers from the file
	//declaring vairables
	ifstream file;
	Node* list1 = NULL, * head1 = NULL, * tail1 = NULL;
	int count=0;
	file.open("Data.txt");

	//inputting numbers into a linked list 
	while (!file.eof()) {
		list1 = new Node;
		if (head1 != NULL && tail1 != NULL) {
			list1->ptr = list1;
		}
		file >> list1->value;
		if (head1 == NULL || tail1 == NULL) {
			head1 = list1;
			tail1 = list1;
		}
		else {
			tail1->ptr = list1;
			tail1 = tail1->ptr;
		}
		count++;
	}

	//if there are less than 10 nodes, then replace the empty spaces with a 0
	if (count != max_num - 1) {
		for (int i = count; i < max_num; i++) {
			list1 = new Node;
			list1->ptr = list1;
			list1->value = 0;
			tail1->ptr = list1;
			tail1 = tail1->ptr;

		}
	}

	//return the linked list back to main
	list1->ptr = nullptr;
	list1 = head1;
	return list1;
}

bool isemptystack(int* arrayEMPTY) { //checks if the array is empty
	if (arrayEMPTY == NULL) {
		return true;
	}
	else {
		return false;
	}
}
bool isfullstack(int *arrayFULL) { //checks if the array is full
	//declaring variables
	bool full = true;
	bool null = false;

	//this algorithm will find the first 0 in the list, if there is a 0, then that means the list is not full
	if (arrayFULL != NULL) {
		for (int i = 0; i < max_num; i++) {
			if (*(arrayFULL + i) == 0) {
				full = false;
				null = false;
				i = 10;
				return false;
			}
		}
	}
	if (arrayFULL == NULL) {
		null = true;
		return false;
	}
	if (full == true && null == false) {
		return true;

	}

}

int push(int pushNUM, int*& arrayPush) { //function will push a number into the top of the stack

	//pushing number into the top of the stack
	if (arrayPush != NULL) {
		for (int i = 0; i < max_num; i++) {
			if (*(arrayPush + i) == 0) {
				*(arrayPush + i) = pushNUM;
				i = 10;
			}
		}
	}

	//if the stack is empty, then create a new array and psuh it into the stack, then replace the empty 9 spaces with 0
	if (arrayPush == NULL) {
		arrayPush = new int[max_num];
		int i = 0;
		*(arrayPush + i) = pushNUM;
		for (i = 1; i < max_num; i++) {
			*(arrayPush + i) = 0;
		}
	}

	//output of the array with the pushed number
	cout << "\nNew array: " << endl;
	for (int k = 0; k < max_num; k++) {
		cout << *(arrayPush + k) << " ";
	}
	cout << "\n" << endl;

	return *arrayPush;
}

int top(int *arrayTop) { //function will find the value of the top number in the stack
	//find the top of the stack if the stack is not full
	if (arrayTop != NULL && isfullstack(arrayTop)==false) {
		for (int i = 0; i < max_num; i++) {
			if (*(arrayTop + i) == 0) {
				return *(arrayTop + (i - 1));
			}
		}
	}
	//find the top of the stack if the stack is full
	else if (isfullstack(arrayTop) == true && arrayTop != NULL) {
		return (*(arrayTop + (max_num - 1)));
	}

	//display null of the stack is empty
	else if (arrayTop == NULL) {
		return NULL;
	}
}

void pop(int* arrayPop) { //function will pop the top number out of the array
	//declaring variables
	int j=0;
	//finds the element where the number is equal to the number on top
	while (arrayPop[j] != top(arrayPop)) {
		j++;
	}
	//replacing the top number with a 0
	arrayPop[j] = 0;

	//outputs the new stack with the popped value
	cout << "New stack: " << endl;
	for (int k = 0; k < max_num; k++) {
		cout << *(arrayPop + k) << " ";
	}
	cout << endl;
}

bool isemptystack(Node* listEmpty) { //function will find if the linked list is empty
	if (listEmpty == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool isfullstack(Node* listFull) { //function will find if the linked list is full
	//declaring variables
	Node *currentFull = listFull;
	int count = 1;
	//if the list is not empty, then find the value where it finds 0.  if it does not find 0, then it is full
	if (listFull != NULL) {
		while (currentFull != nullptr) {
			currentFull = currentFull->ptr;
			if (currentFull->value == 0) {
				return false;
			}
			count++;
			if (count == max_num) {
				return true;
			}
		}
	}
	else {
		return false;
	}
}

Node push(int num, Node* listPush) { //function will push a new node into the linked list
	//declaring variables
	Node* current=listPush, *tailPush=NULL, *headPush=NULL;

	//if the list is not empty, then push a number
	if (listPush != NULL) {
		tailPush = listPush;
		while (current->value != 0) {
			current = current->ptr;
			if (current->value == 0) {
				current->value = num;
				while (tailPush != NULL) {
					cout << tailPush->value << " ";
					tailPush = tailPush->ptr;
				}
				return *listPush;
			}
		}
	}
	//if the list is empty, then create a new node and push the number
	else if (listPush == NULL) {
		listPush = new Node;
		if (headPush != NULL && tailPush != NULL) {
			listPush->ptr = listPush;
		}
		listPush->value = num;
		if (headPush == NULL || tailPush == NULL) {
			headPush = listPush;
			tailPush = listPush;
		}
		else {
			listPush->ptr = listPush;
			listPush = listPush->ptr;
		}

	}

	for (int i = 1; i < max_num; i++) {
		listPush = new Node;
		listPush->ptr = listPush;
		listPush->value = 0;
		tailPush->ptr = listPush;
		tailPush = tailPush->ptr;

	}

	tailPush->ptr = nullptr;
	tailPush = headPush;

	//output the list
	while (tailPush != NULL) {
		cout << tailPush->value << " ";
		tailPush = tailPush->ptr;
	}

	return *listPush;
}

int top(Node* listTop) { //function will find the top of a linked list
	//declaring and initializing variables
	Node* currentTop=listTop;
	//if the list is not full, find the top number by finding 0 first
	if (listTop != NULL && isfullstack(listTop) == false) {
		while (currentTop != nullptr) {
			if (currentTop->ptr->value == 0) {
				return currentTop->value;
			}
			currentTop = currentTop->ptr;
		}
	}
	//if the stack is full, then find the last node
	else if (isfullstack(listTop) == true && listTop != NULL) {
		while (currentTop->ptr != NULL) {
			currentTop = currentTop->ptr;
		}
		return currentTop->value;
	}
	//if the list is empty then return an empty list
	else if (listTop == NULL) {
		return NULL;
	}
}

Node pop(Node* listPop) { //function will pop a number out from the linked list
	//declaring variables
	Node* current=listPop, *tailPop=listPop;
	
	//find the value which the value is equal to the top of the list, then replace it with 0
	while (current->value != top(listPop)) {
		current = current->ptr;
	}
	current->value = 0;

	//output
	cout << "New list: " << endl;

	while (tailPop != NULL) {
		cout << tailPop->value << " ";
		tailPop = tailPop->ptr;
	}
	return *listPop;
}