/*
Main.cpp

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #4
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	A driver program for Assignment 4
This program will allow the user to build a dynamic array
and then will time the sorts.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <regex>
#include <conio.h>
#include "Search.h"
#include "BinarySearchTree.h"

using namespace std;

int ARRAYSIZE = 1000;

	//method to build a new array:
int* GetNewArray()
{
	int* array = new int[ARRAYSIZE];

	for (int i = 0; i < ARRAYSIZE; ++i)
	{
		array[i] = i + 1;
	}
	return array;
}

int main()
{
	time_t timeTaken;
	time_t start;
	time_t stop;
	
	cout << "Tim Andrew (W0212032@nscc.ca) C++ Assignment #4" << endl << flush;
	cout << "-----------------------------------------------" << endl << flush;

	
/*PART1*/
	cout << "Part 1: Sequential and Binary Searching:" << endl << flush;
	cout << "  \"Time the searches for every element in an array of " <<  ARRAYSIZE 
		 << " elements\"" << endl << endl<< flush;

	int* array = GetNewArray();

		//Do a Sequential search:
	start = clock();
	for (int i = 1; i <= ARRAYSIZE; ++i)
	{
		Search::SequentialSearch(array, ARRAYSIZE, i);
	}
	stop = clock();
	timeTaken = (stop - start);
	cout << "\tSequential Search:" << endl << flush;
	cout << "\t\tStart @ " << to_string(start) << endl << flush;
	cout << "\t\tEnd @ " << to_string(stop) << endl << flush;
	cout << "\t\tTime = " << to_string(timeTaken) << "ms." << endl << endl << flush;

		//Do a Binary search:
	start = clock();
	for (int i = 1; i <= ARRAYSIZE; ++i)
	{
		Search::BinarySearch(array, ARRAYSIZE, i);
	}
	stop = clock();
	timeTaken = (stop - start);
	cout << "\tBinary Search:" << endl << flush;
	cout << "\t\tStart @ " << to_string(start) << endl << flush;
	cout << "\t\tEnd @ " << to_string(stop) << endl << flush;
	cout << "\t\tTime = " << to_string(timeTaken) << "ms." << endl << endl << flush;
	cout << "\tPress any key if you dare to view part 2.." << flush;
	_getch();
	cout << endl << endl;

/*PART2*/
	cout << "-----------------------------------------------" << endl << flush;
	cout << "Part 2: Auto-balancing Binary Search Trees:" << endl << flush;
	cout << "  \"Build a console-based spell checker that will show spelling mistakes\"" << endl << endl << flush;
	cout << "\tPress any key to read and display the dictionary tree.." << flush;
	_getch();
	cout << endl << endl;

		//set up a new BinarySearchTree:
	BinarySearchTree bst;

		//some variables to handle file locations:
	string dictionary = "dictionary.txt";
	string document = "mispelled.txt";

	//set up a var to handle the reading of each dictionary word:
	string dictionaryWord;

		//set up an input stream for the dictionary:
	fstream dictionaryInput;
		//open it:
	dictionaryInput.open(dictionary, ios::in);

	if (dictionaryInput) 
	{
			//loop while there is input:
		while (dictionaryInput >> dictionaryWord)
		{

				//add the word to the bst:
			bst.Insert(dictionaryWord);
		}
	}
		//end reading and close file:
	dictionaryInput.close();

	//print it out:
	cout << bst.PrintTree() << endl << endl;
	cout << "\tPress any key to display the dictionary errors in " << document << "..." << flush;
	_getch();
	cout << endl << endl;

	//set up a var to handle the reading of each dictionary word:
	string documentWord;

		//set up a variable to build the error list:
	string errorList = "  Spelling errors in " + document + ":\n\n";
	int wordCount = 0;

	//set up an input stream for the dictionary:
	fstream documentInput;
	//open it:
	documentInput.open(document, ios::in);

	if (documentInput)
	{
		//parse the input and strip  it of puncutation.
		//loop while there is input:
		while (documentInput >> documentWord)
		{
			string checkWord = "";
			for (char& c : documentWord)
					//skip if the char is not alpha or is blank:
				if (!isalpha(c) || isblank(c))
					continue;
				else
					checkWord += tolower(c);

			++wordCount;

				//search if word isn't emppty and doesn't exist:
			if (!checkWord.empty() && !bst.Search(checkWord))
			{
					//append it:
				errorList += "Word " + to_string(wordCount) + ": " + checkWord + "\n";
			}
		}
	}
	//end reading and close file:
	documentInput.close();

		//display word errors:
	cout << errorList;
	

	
	cout << endl << endl << "\tThat's it!  Press any key to quit!" << flush;
	_getch();
	return 0;
}