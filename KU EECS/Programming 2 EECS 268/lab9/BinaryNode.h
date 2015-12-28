//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */
 
#ifndef _BINARY_NODE
#define _BINARY_NODE

#include <stdlib.h>

template<class ItemType>
class BinaryNode
{   
private:
   ItemType              item;           // Data portion
   BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
   BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

public:
   BinaryNode(const ItemType& anItem) :
		item(anItem), leftChildPtr(NULL), rightChildPtr(NULL) {}

   ItemType getItem() const { return item; }

   BinaryNode<ItemType>* getLeftChildPtr() const { return leftChildPtr; }
   BinaryNode<ItemType>* getRightChildPtr() const { return rightChildPtr; }
   
   void setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
		{ leftChildPtr = leftPtr; }
   void setRightChildPtr(BinaryNode<ItemType>* rightPtr)            
		{ rightChildPtr = rightPtr; }
}; // end BinaryNode

#endif 
