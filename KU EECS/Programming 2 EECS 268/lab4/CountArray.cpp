/**
@Filename CountList.cpp
@Author Warren Scipio
*/


using namespace std;

template <typename T>
CountList<T>::CountList(){
	arraySize=10;
	numItemsStored=0;
	array = new Count<T>[arraySize];

}
//deconstructor
template <typename T>
CountList<T>::~CountList(){
	delete [] array;

}

//copy constructor
template <typename T>
CountList<T>::CountList(const CountList<T>& countArr){
	numItemsStored = countArr.numItemsStored;
	arraySize = countArr.arraySize;
	array = new Count<T>[arraySize];

	for (int i=0; i< numItemsStored; i++)
		array[i] = countArr.getItem(i);

}


//bumpcount method to bump up the count of an item and if it was read once dont read again
template <typename T>
void CountList<T>::bumpCount(T t){
bool notAdded = true;
	for (int i=0; i<numItemsStored;i++){
		//if item matches an item in the array
		if(array[i].getItem()== t){
			array[i].addTo();
			notAdded = false;
		}
	}
	//boolean to stop from starting the count on something that has already been counted
	if(notAdded){
		//if the number of items stored is less than the array size set the item to Count 			class item
		if(numItemsStored < arraySize) {
			array[numItemsStored].placeItem(t);
			numItemsStored++;
		}
		else {//double the size of the array if number of items stored is greater or equal to
			arraySize = arraySize*2;
			Count<T> CopyArray[arraySize];
			//give over vaules from old array to temp array
			for (int i=0; i < numItemsStored; i++)
				CopyArray[i] = array[i];
			//delete old array
			delete [] array;
			//give values back to newly created array
			array = new Count<T>[arraySize];
			for (int i=0; i < numItemsStored; i++){
				array[i] = CopyArray[i];
		
			}
		//now set the item to Count class item
		array[numItemsStored].placeItem(t);
		numItemsStored++;
		}

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
	if (itemIndex > numItemsStored)
	itemIndex = numItemsStored;

	return array[itemIndex];
}

