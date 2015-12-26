/**
@Filename Count.h
@Author Warren Scipio
*/

#ifndef _COUNT_
#define _COUNT_


template <typename T>
class Count
{
private:

    T item;
    int count;

public:
	Count();
	Count(T t);
	void addTo();
	T getItem() const;
	int getCount() const;
    
};


#include "Count.cpp"

#endif
