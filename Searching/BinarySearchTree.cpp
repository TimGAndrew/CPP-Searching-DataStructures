/*
BinarySearchTree.cpp

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #4
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The AVL Binary Search Tree Class.

RESOURCE: https://kukuruku.co/post/avl-trees/
*/
#include "BinarySearchTree.h"

	//Public to insert a word into a tree:
void BinarySearchTree::Insert(string word) 
{
		//attempt insert into root node:
	treeTop = Insert(treeTop, word);
}

	//Private method to build a node for the word and inserting a word into the tree (if not a duplicate):
Node* BinarySearchTree::Insert(Node* node, string word)
{
		//if node is null
	if (!node)
	{		
		return new Node(word);
	}

	if (word < node->getWord())
	{		//send it to attempt insert on left node:
		node->setLeftNode(Insert(node->getLeftNode(), word));
	}

	else if (word > node->getWord())
	{		//send it to attempt insert on right node:
		node->setRightNode(Insert(node->getRightNode(), word));
	}
			//otherwise it's the same word so do nothing... but you could add some code here for other things in another project.

		//Balance the node and return:
	return Balance(node);
}

	//Private method to balance a node:
Node* BinarySearchTree::Balance(Node* node)
{
		//check and fix the height on this node before balancing ( valid heights = 1, 0 -1 ):
	FixHeight(node);

		//check if any nodes are (2 or -2)
	if (BalanceFactor(node) == 2)
	{
			//check if its right node is greater than 0 and if so
		if (BalanceFactor(node->getRightNode()) < 0)
				//set it to rotate Right (RightLeft rotation):
			node->setRightNode(RotateRight(node->getRightNode()));

			//rotate left and return:
		return RotateLeft(node);
	}
	else if (BalanceFactor(node) == -2)
	{
			//check if rotateLeft is needed:
		if (BalanceFactor(node->getLeftNode()) > 0)
				//set it to rotate Left (LeftRight rotation):
			node->setLeftNode(RotateLeft(node->getLeftNode()));

			//rotate right and return:
		return RotateRight(node);
	}

		//otherwise no balance required
	return node;
}

	//A method to check and fix the height of a node:
void BinarySearchTree::FixHeight(Node* node)
{
		//get left and right node heights:
	int leftHeight = Height(node->getLeftNode());
	int rightHeight = Height(node->getRightNode());

		//Set the node height (+1 because subnodes are being compared):
	if (leftHeight > rightHeight)
		node->setHeight(leftHeight + 1);
	else
		node->setHeight(rightHeight+ 1);
}

	//A method to return the height of the node:
int BinarySearchTree::Height(Node* node)
{
		//return node's height (or 0 if null)
	return node ? node->getHeight() : 0;
}

	//find out what the balance factor is:
int BinarySearchTree::BalanceFactor(Node* node)
{
	int rightNodeHeight = Height(node->getRightNode());
	int leftNodeHeight = Height(node->getLeftNode());

	return rightNodeHeight - leftNodeHeight;
}

	//The right rotation round node:
Node* BinarySearchTree::RotateRight(Node* node)
{
		//create a new node from incoming node's left node:
	Node* rotatedNode = node->getLeftNode();

		//set incoming node's left node to rotated node's right node:
	node->setLeftNode(rotatedNode->getRightNode());

		//set rotated node's right node to incoming node:
	rotatedNode->setRightNode(node);

		//fix heights:
	FixHeight(node);
	FixHeight(rotatedNode);

		//return node:
	return rotatedNode;
}

	//The left rotation round node (comments the inverse of right):
Node* BinarySearchTree::RotateLeft(Node* node)
{
	Node* rotatedNode = node->getRightNode();

	node->setRightNode(rotatedNode->getLeftNode());

	rotatedNode->setLeftNode(node);

	FixHeight(node);
	FixHeight(rotatedNode);

	return rotatedNode;
}

	//Public method to access PrintTree:
string BinarySearchTree::PrintTree()
{
		//get output string from PrintTree:
	return PrintTree(treeTop, "");
}

	//Private method to get print out of tree:
string BinarySearchTree::PrintTree(Node* node, string indent)
{
	string treePrintOut = "";
	if (node) 
	{
			//add the output from the right node:
		treePrintOut += PrintTree(node->getRightNode(), indent += "\t");

			//if this is the treetop output a notice:
		if (node == treeTop)
				treePrintOut += "[TREETOP]> ";

			//output the intent and this current word:
		treePrintOut += indent + node->getWord() + "\n";

			//add the output from the left node:
		treePrintOut += PrintTree(node->getLeftNode(), indent += "\t");

	}
	return treePrintOut;
}

	//Public method to search tree:
bool BinarySearchTree::Search(string word)
{
	return Search(treeTop, word);
}

	//Private method to search tree:
bool BinarySearchTree::Search(Node* node, string word)
{
	if (node)
			//if there is a word match 
		if (node->getWord() == word ||		///or if either left or right recursive search has a match:
			(Search(node->getLeftNode(), word) || Search(node->getRightNode(), word)))
			return true;
	return false;
}
