/*
Node.h

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #4
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	A Header File for the Node Class.
*/
#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node
{
private:
		//Node properties:
	Node* leftNode;
	Node* rightNode;
	int avlHeight;
	string dictionaryWord;

public:
		//Constructors and destructors:
	Node(string word);
	virtual ~Node();

		//Node behaviours:
	Node* getLeftNode();
	void setLeftNode(Node* left);

	Node* getRightNode();
	void setRightNode(Node* right);

	string getWord();
	void setWord(string word);

	int getHeight();
	void setHeight(int height);
};
#endif NODE_H


