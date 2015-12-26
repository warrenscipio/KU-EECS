/**
@Filename CountArray.h
@Author Warren Scipio
*/

#ifndef _COUNTARRAY_H
#define _COUNTARRAY_H
#include "Count.h"



template <typename T>
class CountArray
{
private:

    Count<T>* array;
    
    int arraySize; // initially: 10
    int numItemsStored;
public:
    //contructor
    CountArray();
    //copy constructor
    CountArray(const CountArray<T>& countArr);
    //deconstructor
    ~CountArray();
    // method to bump the count of an item
    void bumpCount(T t);
    int getNumItemsStored() const;
    Count<T> getItem(int whichItem) const;
};



#include "CountArray.cpp"

#endif
