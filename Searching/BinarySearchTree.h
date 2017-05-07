/*
BinarySearchTree.h

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #4
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	A Header File for the AVL Binary Search Tree Class.
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <string>
#include "Node.h"

using namespace std;

class BinarySearchTree
{
public:
	BinarySearchTree() : treeTop(NULL) {};
	~BinarySearchTree() {};

	void Insert(string word);
	bool Search(string word);

	string PrintTree();
private:
	Node* treeTop;
	Node* Balance(Node* node);
	Node* Insert(Node* node, string word);
	Node* RotateRight(Node* node);
	Node* RotateLeft(Node* node);

	string PrintTree(Node* node, string indent);

	int Height(Node* node);
	int BalanceFactor(Node* node);

	void FixHeight(Node* node);
	bool Search(Node* node, string word);
};
#endif BINARYSEARCHTREE_H


