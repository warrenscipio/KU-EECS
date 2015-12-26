/**
@Filename Executive.cpp
@Author Warren Scipio
*/

#include "Executive.h"
#include <string>

using namespace std;

Executive::Executive(){
int times=0;

}
//constructor calls the read method
Executive::Executive(istream& charFile, istream& intFile, istream& stringFile){


read(charFile, charArray, "Char file.");
read(stringFile, strArray, "String file.");
read(intFile, intArray, "Int file.");


}
//read meathod
template <typename T>
void Executive::read(istream& is, CountList<T>& arr, string name){
	//count to keep track to print every 5 
	int count=0;
	int times=0;
	
	T t;
	
	cout<<endl;
	
	while(is >> t){
		count++;
		// while reading call an instance of CountList to use the method bump count
		arr.bumpCount(t);
		//call method to print out every 5

		if (count%5 ==0){
		times++;
		
		
		print(arr);
		}
		
		
		
		

	}
	//prints out remaining items if number of items isnt divisible by 5
	if (count%5!=0){
		cout << "Printing out the remaining " << count-(5*times) << " item(s) from the " << name << " (for a total of " << count << ")" << endl;
		print(arr);
	}
	cout<<"------------------------------------------------------------------------------"<<endl;


}


//printing method to print every item and count 
template <typename T>
void Executive::print(CountList<T> arr){ // arr MUST be passed by value
	 
	
	
	for (int i=0; i <arr.getNumItemsStored(); i++) {
	
	cout << "(" << arr.getItem(i).getItem() << ", " << arr.getItem(i).getCount() << ") " << endl;
}
cout << endl;
}
	




//printing final result
void Executive::print() const{
cout << "recorded in the CharFile: " <<endl; 
print(charArray);

cout << "recorded in the String File:  " << endl;
print(strArray);

cout << "recorded in the Int File: " << endl;
print(intArray);

}




