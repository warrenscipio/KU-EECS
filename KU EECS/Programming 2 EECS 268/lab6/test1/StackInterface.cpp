#include "StackInterface.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

StackInterface::StackInterface(){

}


virtual bool isEmpty() const = 0;


virtual void push(const ItemType& newEntry)
		throw (PrecondViolatedExcep) = 0;

virtual void pop()
		throw (PrecondViolatedExcep) = 0;


 virtual ItemType peek() const throw (PrecondViolatedExcep) = 0;

