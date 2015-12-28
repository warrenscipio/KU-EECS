/**
@Filename CountList.h
@Author Warren Scipio
*/

#ifndef _COUNTLIST_H
#define _COUNTLIST_H
#include "Count.h"
#include "node.h"



template <typename T>
class CountList
{
private:

    Node<Count<T> >* firstPtr;
    int numItemsStored;

public:
    //contructor
    CountList();
    //copy constructor
    CountList(const CountList<T>& countArr);
    //deconstructor
    ~CountList();
    // method to bump the count of an item
    void bumpCount(T t);
    int getNumItemsStored() const;
    Count<T> getItem(int whichItem) const;
};



#include "CountList.cpp"

#endif
