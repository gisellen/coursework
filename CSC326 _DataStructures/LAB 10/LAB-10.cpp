/*
CSC 326
Lab 10

PURPOSE
This lab is a modification of lab 9.  In this lab, I added a function that will sort the list.  The purpose of this lab is to show how linked lists are created in a basic way and used.  There are a set of options that will be implemented in this code
to manipulate the linked list based on the option that is chosen.  The options that can be chosen is:
o  searching the list if a number exists
o  adding a number to the beginning of the list
o  deleting a number for the list
o  sort the list

The input will consist of numbers that will be inputted by the user

The output will be the same as the last lab except that when the user chooses the sort option.  It will output the list after it has been sorted by the
algorithm.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//declaring the class for linked list
class Node {
public:
    int data;
    Node* next;
};

//prototypes
void search(Node*, Node*, int);
void add(Node*, Node*, int);
void sort(Node*, Node*);
void deletenode(Node*, Node*, int);

int main()
{
    //declaring varibales
    Node* list, * head, * tail;
    int input = 0, input1 = 0, count = 0;
    char num;
    ifstream file;
    ofstream outfile;
    bool restart = true, empty = false, cont = true;
    //initializing variables
    list = NULL;
    head = NULL;
    tail = NULL;

    outfile.open("Text.txt");
    if (outfile.fail())
        cout << "The file cannot be written." << endl;

    //getting user input
    while (restart == true) {
        cout << "Please input a number (type 999 for an empty list): \n";
        cin >> input;
        if (input != 999) {
            outfile << input;
            cout << "Would you like to add another number? (y/n): " << endl;
            cin >> num;
            count++;
            if ('y' == num) {
                restart = true;
                outfile << " ";
            }
            else if ('n' == num)
                restart = false;
        }
        else {
            //checking if the list is null
            cout << "The list is empty.";
            restart = false;
            empty = true;
        }
    }

    //stop preventing from writing into the file
    outfile.close();

    if (empty == false) {
        //if file has inputs, open the file.
        file.open("Text.txt");
        if (file.fail())
            cout << "The file cannot be opened." << endl;

        //getting input from file

        while (!file.eof()){
            list = new Node;
        if (head != NULL && tail != NULL) {
            list->next = list;
        }
            file >> list->data;
            if (head == NULL || tail == NULL) {
                head = list;
                tail = list;
            }
            else {
                tail->next = list;
                tail = tail->next;
            }
            // this checks if the linked list have been linked perfectly
            cout << "list: " << list->next << endl;
            cout << "head: " << head->data << endl;
            cout << "tail: " << tail->data << endl;
            cout << endl;

            count++;
        }
        list->next = nullptr;

        //outputting the linked list
        cout << "There are " << count << " number(s) in the list \n" << endl;

        //user will be able to interact with this program when it starts outputting
        cout << "Press 1 to search" << endl;
        cout << "Press 2 to add number to list" << endl;
        cout << "Press 3 to delete number from list" << endl;
        cout << "Press 4 to sort the list" << endl;
        cout << "Press 5 to end file" << endl;

        cin >> input;
        cout << endl;

        //outputting the options based on the option chosen
        if (input == 1) {
            cout << "Please enter a number to search for: ";
            cin >> input1;
            search(list, head, input1);
        }
        else if (input == 2) {
            cout << "Please enter a number to add to the beginning of the list: ";
            cin >> input1;
            add(list, head, input1);
        }
        else if (input == 3) {
            cout << "Please enter a number to delete: ";
            cin >> input1;
            deletenode(list, head, input1);
        }
        else if (input == 4) {
            sort(list, head);
        }
        else if (input == 5) {
            file.close();
        }


        file.close();
    }

    return 0;
} //end of main

void search(Node* list1, Node* headptr, int num1) { // this function seaches for the number given by the user. 
    //declaring variables
    bool search = false;
    bool missing = false;

    //initializing

    list1 = headptr; //list1 will point to the beginning of the list

    while (search == false && list1->next != nullptr) {
        if (list1->data == num1)
        {
            search = true;
        }
        list1 = list1->next;
    }
    if (search == true) {
        cout << "The number " << num1 << " is on this list!" << endl;
    }
    else {
        cout << "There is no such item in the list.";
    }
}

void add(Node* list3, Node* headptr3, int num3) { //this function will add a node into the beginning of the list
    //declaring variables
    Node* add, * ptr3;
    int listnum;
    //output what's going to happen
    cout << "The number " << num3 << " will be added to the beginning of the list." << endl;

    ptr3 = headptr3;
    list3 = headptr3;



    //adding new number into node
    add = new Node;
    add->data = num3;
    add->next = headptr3;

    headptr3 = add;
    list3 = add;

    //outputting the list after the list after the number has been added
    cout << "new list: " << endl;
    while (list3->next != nullptr) {
        cout << list3->data << endl;
        list3 = list3->next;
        if (list3->next == nullptr) //if next is nullptr, cout the last item in the list
            cout << list3->data;
    }
}

void deletenode(Node* list2, Node* headptr2, int num2) { //this function will delete a node from the list
    //declaring variables
    Node* del, * ptr;
    del = headptr2;
    ptr = headptr2;
    list2 = headptr2;
    bool search1 = false;
    bool missing = false;

    //search for the node
    while (search1 == false || missing == false) {
        if (del->data == num2)
        {
            if (del->next == nullptr) {
                delete del;
            }
            else {
                while (ptr->next->data != num2) {
                    ptr = ptr->next;
                }
                cout << "pointer: " << ptr->data << endl;
                cout << "del: " << del->data << endl;
                ptr->next = del->next;
                cout << "pointer next: " << ptr->next->data << endl;
                delete del;
                del = NULL;
                cout << "current pointer: " << ptr->next->data << endl;
                cout << "This number has been deleted from the list!" << endl;
                search1 = true;

            }
            //output the new list
            list2 = headptr2;
            cout << "new list: " << endl;
            while (list2->next != nullptr) {
                cout << list2->data << endl;
                list2 = list2->next;
                if (list2->next == nullptr) //if next is nullptr, cout the last item in the list
                    cout << list2->data;
            }
        }
        
        //if the number does not exist, then outputthat it doesn't exist
        if (del->next == nullptr) {
            cout << "There is no such item in the list." << endl;
            missing = true;
        }

        //continue searching through the list of it is not equal
        if (search1 != true || missing != true) {
            del = del->next;
        }

    }

}

void sort(Node* list4, Node* headptr4) { //put them into an array, sort, then profit.
    //declaring variables
    Node* sorted, * head, * last;
    int temp = 0;
    list4 = headptr4;
    head = headptr4;
    last = headptr4;

    //begin sorting algorithm
    while (head != NULL) {
        cout << "working sort...";
        last = head->next;
        while (last != NULL) {
            if (head->data > last->data) {
                temp = head->data;
                head->data = last->data;
                last->data = temp;
            }
            last = last->next;
        }
        cout << head->data << " ";
        head = head->next;
    }

        //output sorted list
        cout << "\n Sorted list: " << endl;
        list4 = headptr4;
        while (list4 != nullptr) {
            cout << list4->data << " ";
            list4 = list4->next;
        }
        
}

