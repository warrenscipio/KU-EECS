#include <cassert>
#include "Stack.h"

template<class ItemType>
Stack<ItemType>::Stack(){
	top = -1;
}//end of default constructor

template<class ItemType>
bool Stack<ItemType>::isEmpty() const{
	return top < 0;
}

template<class ItemType>
void Stack<ItemType>::push(const ItemType& newEntry) throw (PrecondViolatedExcep){
	
	//does stack have room for newentry
	if(top < MAX_STACK -1){
		top++; 
		items[top] = newEntry;
	
	}else
		throw PrecondViolatedExcep("Error in Stack::push stack is full cannot add more to the stack");
	
}

template<class ItemType>
void Stack<ItemType>::pop() throw (PrecondViolatedExcep){
	
	if(!isEmpty()){
		top--;
	
		
	}else
		throw PrecondViolatedExcep("Error in Stack::pop cant take out what isnt there...");
}

template<class ItemType>
	ItemType Stack<ItemType>::peek() const throw (PrecondViolatedExcep){

	if(!isEmpty())// enforce precondition
		return items[top];
	else
		throw PrecondViolatedExcep("Error theres nothing to peek at");
}

	

