// lab 9
// nov 29, 2018
// purpose: to change dna to rna

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
using namespace std;

void DNAtoRNA(char[]);
int main()
{
	int i = 0;
	char DNAinput[100];

	cout << "Input a DNA and press enter: " << endl;
	cin.getline(DNAinput, 100);
	cout << "\n\n\n" << endl;
	
	cout << "The RNA is:" << endl;
	DNAtoRNA(DNAinput);
}

void DNAtoRNA(char a[])
{
	int count=0;
	char RNA[100];
	for (int x = 0; x < 100; x++)
	{
		if (a[x] == 'A')
		{
			if (x==0)
				strcpy_s(RNA, "U");
			else 
				strcat_s(RNA, "U");
			count++;
		}
		else if (a[x] == 'T')
		{
			if (x==0)
				strcpy_s(RNA, "A");
			else
				strcat_s(RNA, "A");
			count++;
		}
		else if (a[x] == 'C')
		{
			if (x==0)
				strcpy_s(RNA, "G");
			else
				strcat_s(RNA, "G");
			count++;
		}
		else if (a[x] == 'G')
		{
			if (x==0)
				strcpy_s(RNA, "C");
			else
				strcat_s(RNA, "C");
			count++;
		}
	}
	RNA[count] = '\0';
	for (int x = 0; x < count; x++)
		cout << RNA[x];
}

