/**
@Filename CountList.cpp
@Author Warren Scipio
*/
#include <iostream>

using namespace std;

template <typename T>
CountList<T>::CountList(){
	
	numItemsStored=0;
	firstPtr = nullptr;
	

}
//deconstructor
template <typename T>
CountList<T>::~CountList(){
	Node<Count<T> >* temp = nullptr;

	for (int i=0; i< numItemsStored; i++){
		temp = firstPtr->getNext();
		delete firstPtr;
		firstPtr = temp;
	}


}

//copy constructor
template <typename T>
CountList<T>::CountList(const CountList<T>& countArr){

	Node<Count<T> >* list1= nullptr;
	Node<Count<T> >* list2 = countArr.firstPtr;	
	numItemsStored = countArr.numItemsStored;
	
	for (int i=0; i< numItemsStored; i++){
		if(i<1){
			Count<T> t = list2->getItem();
			firstPtr = new Node<Count<T> >(t); 
			list1 = firstPtr;
			list2 = list2->getNext();
		//first time through
		}else{

			Count<T> t = list2->getItem();
			
			Node<Count<T> >* n = new Node<Count<T> >(t);
			list1->setNext(n);
			list1 = n;
			list2 = list2->getNext();
				
		}
		

		
		
	}
}


//bumpcount method to bump up the count of an item and if it was read once dont read again
template <typename T>
void CountList<T>::bumpCount(T t){
	
	//covers 5 cases of getting new item
	if(firstPtr != nullptr){

		Node<Count<T> >* pointer = firstPtr;
		Node<Count<T> >* pointer2 = nullptr;
		//not the first item
		while(pointer !=nullptr ){
			Count<T> c = pointer->getItem();
			//items equals each other
			if(c.getItem()==t){
				c.addTo();
				pointer->setItem(c);
				break;
			
			}else if(c.getItem()>t){
				//middle
				if(pointer!=firstPtr){

					Count<T> ct(t);
					Node<Count<T> >* n = new Node<Count<T> >(ct,pointer);
					pointer2->setNext(n);
					numItemsStored++;
					break;
				}else{
					Count<T> ct(t);
					Node<Count<T> >* n = new Node<Count<T> >(ct,pointer);
					firstPtr = n;
					numItemsStored++;
					break;
					
				}
				
			}else{
				pointer2 = pointer;
				pointer = pointer->getNext();
				
				 
			}
		}
		//behind list
		if(pointer == nullptr){
			Count<T> last(t);
			Node<Count<T> >* n = new Node<Count<T> >(last,pointer);
			pointer2 -> setNext(n);
			numItemsStored++;
			
			
		}
	//first item of the list
	}else {
		Count<T> c(t);
		Node<Count<T> >* n = new Node<Count<T> >(c);
		firstPtr = n;
		numItemsStored++;
	}
	
	
	
}





// returns number of items stored
template <typename T>
int CountList<T>::getNumItemsStored() const {
	return numItemsStored;
}

//returns a specific item of that index in the array
template <typename T>
Count<T> CountList<T>::getItem(int itemIndex) const{
	//if the requested index is larger than the number of items stored it returns the last item 		in the array
	
	Count<T> t;
	if (itemIndex < numItemsStored){

		Node<Count<T> >* temp = firstPtr;
		for(int i=0; i < itemIndex; i++){
			temp = temp->getNext();

		}
		t = temp->getItem();
	}
		
	return t;

	

	
}

