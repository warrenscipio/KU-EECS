/**
@file GeneralTree.h
@author Warren Scipio */

#ifndef _GENERAL_TREE
#define _GENERAL_TREE

#include "BinaryNode.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>

using namespace std;

template <typename T>
class GeneralTree
{





private:
	BinaryNode<T>* rootPtr;
	

public:

	
	GeneralTree();
	// sets root and calls build tree
	GeneralTree(istream& file);
	// prints out tree
	void printTree(BinaryNode<T>* n, string s) const;
	// builds the tree based on the (
	void buildTree(istream& inp, BinaryNode<T>* n);
	// takes in user commands
	void getCommands();
	// find the child of the requested node or nodes
	void findChild(T i, BinaryNode<T>* n, bool& boo, int& aoo) const;
	// finds the parents of the requested node or nodes
	bool findParent(T i, BinaryNode<T>* n, bool& boo) const;
	// export the tree in the print format
	void exportTree(ostream& output, BinaryNode<T>* n) const;
	// find the siblings of the requested node
	void findSiblings(T i, BinaryNode<T>* n, int& j)const;
	// add a child in the front of the children list
	void addFirst(T i, int j, BinaryNode<T>* n, bool& boo)const;
	// add a child a the back of the children list
	void addLast(T i, int j, BinaryNode<T>* n, bool& boo)const;
	// remove requested node or nodes
	void removeNode(T i, BinaryNode<T>* n, bool& boo) throw (exception);
	// read in new file without exiting program
	void read(istream& file);



};
#include "GeneralTree.cpp"
#endif