/*
Search.h

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #4
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	A Header File for the Search Class.
*/
#ifndef SEARCH_H
#define SEARCH_H

using namespace std;

class Search
{
public:
	//Searching methods:
	static int SequentialSearch(int*& array, int arraySize, int searchNumber);
	static int BinarySearch(int*& array, int arraySize, int searchNumber);
};

#endif SEARCH_H



