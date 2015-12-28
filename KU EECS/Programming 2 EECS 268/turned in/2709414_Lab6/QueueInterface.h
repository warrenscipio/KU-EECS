//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 13-1.
 @file QueueInterface.h */

#ifndef _QUEUE_INTERFACE
#define _QUEUE_INTERFACE
#include "PrecondViolatedExcep.h"

template<typename ItemType>
class QueueInterface

{
public:
   /** Sees whether this queue is empty.
    @return True if the queue is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to the back of this queue.
    @pre an enqueue is possible
    @post If the operation was successful, newEntry is at the 
       back of the queue.
    @param newEntry  The object to be added as a new entry. */
   virtual void enqueue(const ItemType& newEntry)
		throw (PrecondViolatedExcep) = 0;
   
	/** Removes the front of this queue.
     @pre The queue is not empty.
     @post If the operation was successful, the front of the queue 
       has been removed. */
   virtual void dequeue()
		throw (PrecondViolatedExcep) = 0;
   
   /** Returns the front of this queue.
    @pre The queue is not empty.
    @post The front of the queue has been returned, and the
       queue is unchanged.
    @return The front of the queue. */
   virtual ItemType peekFront() const
		throw (PrecondViolatedExcep) = 0;
}; // end QueueInterface
#endif
