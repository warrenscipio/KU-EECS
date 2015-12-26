#include "QueueInterface.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

QueueInterface::QueueInterface(){

}


virtual bool isEmpty() const = 0;



virtual void enqueue(const ItemType& newEntry)
		throw (PrecondViolatedExcep) = 0;



virtual void dequeue()
		throw (PrecondViolatedExcep) = 0;


virtual ItemType peekFront() const
		throw (PrecondViolatedExcep) = 0;

