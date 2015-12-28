#ifndef _QUEUE_
#define _QUEUE_

#include "QueueInterface.h"
#include "PrecondViolatedExcep.h"
const int MAX_NAMES = 100;

template<class ItemType>
class Queue : public QueueInterface<ItemType>{

private:
	ItemType names[MAX_NAMES];//Pointer to list of queue item
	int front;
	int count;

public:
	Queue();
	Queue(const Queue& aQueue);
	bool isEmpty() const;
	void enqueue(const ItemType& newEntry) throw (PrecondViolatedExcep);
	void dequeue() throw (PrecondViolatedExcep);

	//throw if queue is empty
	ItemType peekFront() const throw(PrecondViolatedExcep);
};
#include "Queue.cpp"
#endif
