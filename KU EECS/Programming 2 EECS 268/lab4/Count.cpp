/**
@Filename Count.cpp
@Author Warren Scipio
*/

#include "Count.h"
#include <string>

using namespace std;
//constructor start count at 0
template <typename T>
Count<T>::Count(){
	count = 0;

}

//method to give vaule to item
template <typename T>
 Count<T>::Count(T t){
	item=t;
	count=1;
	

}
//method to increase count
template <typename T>
void Count<T>::addTo(){
	count++;
}



//method to give item to another class to use
template <typename T>
T Count<T>::getItem() const{
return item;
}

//method to give count to another class to use
template <typename T>
int Count<T>::getCount() const{
	return count;
}

	

