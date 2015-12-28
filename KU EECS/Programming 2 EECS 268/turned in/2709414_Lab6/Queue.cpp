#include <cassert>
#include "Queue.h"
#include "iostream"

template<class ItemType>
Queue<ItemType>::Queue(){
	for(int i=0; i < MAX_NAMES; i++){
		names[i]="#";
	}
	front = 0;
	count = 0;
}//end of default constructor

template<class ItemType>
bool Queue<ItemType>::isEmpty() const{
	bool empty = false;
	
	for(int i=0; i < MAX_NAMES; i++){

		if(names[i].compare("#")!=0){
			empty = false;
			return empty;
		}	
		empty = true;
	}
	return empty;
		
}

template<class ItemType>
void Queue<ItemType>::enqueue(const ItemType& newEntry) throw (PrecondViolatedExcep){
	
	//does Queue have room for newentry
	if(count < MAX_NAMES-1){
		
		names[count] = newEntry;
		count++; 
	
	}else
		throw PrecondViolatedExcep("Sorry the building has reached maximum capacity come back later");
	
}

template<class ItemType>
void Queue<ItemType>::dequeue() throw (PrecondViolatedExcep){
	
	if(!isEmpty()){
		names[front]="#";
		front++;
	 
		
		
	}else
		throw PrecondViolatedExcep("Error Queue::dequeue nothing in Queue to dequeue");
}

template<class ItemType>
ItemType Queue<ItemType>::peekFront() const throw (PrecondViolatedExcep){

	if(!isEmpty())// enforce precondition
		return names[front];
	else
		throw PrecondViolatedExcep("Error Queue::peek nothing to peek at in queue");

}

	

