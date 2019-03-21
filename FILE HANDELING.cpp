// ConsoleApplication98.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
int AC(char Data[100])
{


	ifstream READ("Input.txt", ios::in); // input object is created

	char INPUT[100];
	if (READ.is_open())
	{

		for (int i = 0; i < 100; i++)
		{
			READ >> noskipws >> INPUT[i];   // so that all the spaces are read

		}
	}

	cout << "See the magic in the files " << endl;


	READ.close();

	char REAL[100];
	for (int i = 0; i < 100; i++)
	{
		REAL[i] = INPUT[i];
	}

	ofstream PRINT("Output.txt", ios::out);  // output object
	int counter = 0, counter_SPECIAL_CHARACTERS = 0, counter_UPERCASE_CHARACTERS = 0, counter_LOWERCASE_CHARACTERS = 0;
	if (!PRINT)   // if object cannot be used by any reason...the following message will be displayed...
	{
		cout << "File could not be loaded";
		return 1; // show error 
	}
	// if following conditions are met then the following counters will be incremented
	for (int i = 0; i < 100; i++)
	{
		if (((REAL[i] >= 'a') && (REAL[i] <= 'z')) || ((REAL[i] >= 'A') && (REAL[i] <= 'Z'))) // lower case and upper case letters
		{
			counter++;
		}
		if (((REAL[i] >= 'a') && (REAL[i] <= 'z')))  // lower case
		{
			counter_LOWERCASE_CHARACTERS++;
		}
		if (((REAL[i] >= 'A') && (REAL[i] <= 'Z')))   // upper case
		{
			counter_UPERCASE_CHARACTERS++;
		}
		if (REAL[i] == ' ')  // for counting spaces
		{
			counter_SPECIAL_CHARACTERS++;
		}



	}
	// just sending the value of counters into the file
	PRINT << "The number of alphabets are  " << counter << " (excluding special characters and spaces) " << endl;
	PRINT << "The number of UPPER CASE LETTERs are  " << counter_UPERCASE_CHARACTERS << endl;
	PRINT << "The number of LOWER CASE LETTERs are " << counter_LOWERCASE_CHARACTERS << endl;
	PRINT << "The number of white spaces are  " << counter_SPECIAL_CHARACTERS << endl;


	PRINT.close();

}

void  Count_lines_And_Words_PER_Second(string);

int main()
{
	char INPUT[100];

	AC(INPUT);
	Count_lines_And_Words_PER_Second(INPUT);  // function calling
}



void Count_lines_And_Words_PER_Second(string Second_Input_TWO)
{
	ofstream SMASH("Output.txt", ios::app);
	ifstream READ("Input.txt", ios::in);
	if (!READ)
	{
		cout << "No such file exists" << endl;

	}
	int 	counter = 0, counter_for_number_of_words_in_a_Line = 1;

	while (!READ.eof())  // will read the file until the end of file is reached
	{



		getline(READ, Second_Input_TWO);  // to read data fromthe file by each line 

		for (int i = 0; i < Second_Input_TWO.size(); i++)
		{
			if (Second_Input_TWO[i] == ' ')
			{
				// as each space means that there must be a word before it so we are counting them with the help of spaces
				counter_for_number_of_words_in_a_Line++;
				SMASH << endl;
			}

		}

		SMASH << "The number of word in line no : " << counter + 1 << " is " << counter_for_number_of_words_in_a_Line++;
		counter++;
		counter_for_number_of_words_in_a_Line = 1;
	}


	SMASH << endl;



	SMASH << "The total number of lines are " << counter << endl;
	READ.close();
	SMASH.close();

}
