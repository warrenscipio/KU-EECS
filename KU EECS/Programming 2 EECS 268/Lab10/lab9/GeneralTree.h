
#ifndef _GENERAL_TREE
#define _GENERAL_TREE

#include "BinaryNode.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>

using namespace std;


class GeneralTree
{





private:
	BinaryNode<int>* rootPtr;
	

public:


	GeneralTree();
	GeneralTree(char* file);
	void printTree(BinaryNode<int>* n, string s) const;
	void buildTree(istream& inp, BinaryNode<int>* n);

	void getCommands();
	void findChild(int i, BinaryNode<int>* n, bool& boo, int& aoo) const;
	bool findParent(int i, BinaryNode<int>* n, bool& boo) const;
	void exportTree(ostream& output, BinaryNode<int>* n) const;
	void findSiblings(int i, BinaryNode<int>* n, int& j)const;
	void addFirst(int i, int j, BinaryNode<int>* n, bool& boo)const;
	void addLast(int i, int j, BinaryNode<int>* n, bool& boo)const;
	void removeNode(int i, BinaryNode<int>* n, bool& boo) throw (exception);



};
#endif
