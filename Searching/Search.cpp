/*
Search.cpp

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #4
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The Search Class.
*/
#include "Search.h"

int Search::SequentialSearch(int*& array, int arraySize, int searchNumber)
{
		//iterate through each element:
	for (int i = 0; i < arraySize; ++i)
	{
			//If the searchNumber is found:
		if (array[i] == searchNumber)
		{
				//return the index:
			return i;
		}
	}
		//If its not found return -1:
	return -1;
}

int Search::BinarySearch(int*& array, int arraySize, int searchNumber)
{
		//set the initial variables:
	int low = 0;
	int high = arraySize - 1;
	int middle;

		//keep searching until you find the middle or until low > high:
	while (low <= high)
	{
			//set the middle variable:
		middle = (low + high) / 2;

			//if the searchNumber is in the middle element:
		if (searchNumber == array[middle])
		{
			return middle;
		}
			//otherwise if it's higher than the middle:
		else if (searchNumber > array[middle])
		{
				//set the low as middle plus 1:
			low = middle + 1;
		}
			//if not
		else
		{
				// set the high as middle minus 1:
			high = middle - 1;
		}
	}
		//searchNumber not found, return -1:
	return -1;
}
