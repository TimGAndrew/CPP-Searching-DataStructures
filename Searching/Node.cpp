/*
Node.cpp

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #4
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The Node Class.
*/
#include "Node.h"

	//Constructors and destructors:
Node::Node(string word) : rightNode(NULL), leftNode(NULL), dictionaryWord(word) {}
Node::~Node() {}

	//Node behaviours:
Node* Node::getLeftNode() { return leftNode; }
void Node::setLeftNode(Node* left) { leftNode = left; }

Node* Node::getRightNode() { return rightNode; }
void Node::setRightNode(Node* right) { rightNode = right; }

string Node::getWord() { return dictionaryWord; }
void Node::setWord(string word) { dictionaryWord = word; }

int Node::getHeight() { return avlHeight; }
void Node::setHeight(int height) { avlHeight = height; }