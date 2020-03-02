/*
// csc 326   
// lab 4: using dynamic storage allocation    
/* 
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
    int* p; 
    int i, k, j, l; // variables to be used in loops 
    int temp, high; 
    infile.open("Data.txt"); 
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
  
    //delete dynamic variable 
    delete p; 
    return 0; 
} 