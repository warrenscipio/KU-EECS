#ifndef _STACK_
#define _STACK_

#include "PrecondViolatedExcep.h"
#include "StackInterface.h"
//#define MAX_STACK 10;
const int MAX_STACK = 10;


using namespace std;

template<class ItemType> 
class Stack : public StackInterface<ItemType>
{


public:
	Stack();
	bool isEmpty() const;
	void push(const ItemType& newEntry) throw (PrecondViolatedExcep);
	void pop() throw (PrecondViolatedExcep);
	ItemType peek() const throw (PrecondViolatedExcep);
	
	
	
	
private:
	ItemType items[MAX_STACK];
	int top;
	
	
	


};
#include "Stack.cpp"
#endif
