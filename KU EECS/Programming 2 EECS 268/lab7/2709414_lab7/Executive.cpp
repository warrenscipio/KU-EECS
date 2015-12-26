/**
@Filename Executive.cpp
@Author Warren Scipio
*/

#include "Executive.h"
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>


using namespace std;

Executive::Executive(){//1

}//1

Executive::Executive ( char* size, char* data, char* method) {//1
	
	
		
	arraySize = atoi(size);
/* this made it so it would print out a col for me so I could copy and paste it to the spread sheet
	for(int i=0; i<7;i++){
		double *array;

		switch(i){

		case 0 :arraySize=50000;
		break;
		
		case 1 :arraySize=125000;
		break;

		case 2 :arraySize=250000;
		break;

		case 3 :arraySize=325000;
		break;
		
		case 4 :arraySize=400000;
		break;

		case 5 :arraySize=500000;
		break;

		case 6 :arraySize=1000000;
		break;

		default: cout<< "broke"<<endl;
		break;
		
	}	
*/
		double *array;
		array = new double[arraySize];
		
		
		
		dataOrder(data,array);
		sortMethod(method,array);
	//delete array;
	//}
	


}
void Executive::dataOrder(char data[],double array[]){

	string word(data);

	if(word == "random"){
		srand((unsigned)time(0));

		for(int i=0; i<arraySize;i++){
			array[i] = (rand() % 100000);
			
		}
		
	
	}else if(word == "ascending"){
		for(int i=0; i<arraySize;i++)
			array[i] = 0.001*static_cast<double>(i);

	}else if(word == "descending"){
		for(int i=0; i<arraySize; i++)
			array[i] = 0.001*static_cast<double>(arraySize-i-1);

	}else{
		cout << "Please enter random, ascending or decending as the second argument." <<endl;
		exit(0);
	}
	

}	

void Executive::sortMethod(char method[], double array[]){


	unsigned long time1;
	unsigned long time2;
	string word(method);
	//cout << "sorting method is sorting..." << endl;
	
	if(word == "selection"){
		time1 = getTime();
		selectionSort(array, arraySize);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);
	
	}else if(word == "insertion"){
		
		time1 = getTime();
		insertionSort(array, arraySize);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);

	}else if(word == "bubble"){

		time1 = getTime();
		bubbleSort(array, arraySize);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);

	}else if(word == "merge"){

		time1 = getTime();
		mergesort(array, arraySize);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);

	}else if(word == "quick"){

		time1 = getTime();
		quicksort(array, arraySize);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);

	}else{
		cout << "Choose a sorting method for the third argument, options:" << endl;
		cout << "(selection)" << endl;
		cout << "(insertion)" << endl;
		cout << "(bubble)" << endl;
		cout << "(merge)" << endl;
		cout << "(quick)" << endl;
		exit(0);
	}

	
}



unsigned long Executive::getTime(void)
      {
     	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec*1000000ul +tv.tv_usec;

      }

void Executive::printArray(double array[]){

for(int i=0; i<arraySize;i++){
		cout << array[i] << endl;
		}
}

void Executive::printTime(unsigned long t1, unsigned long t2){
unsigned long time = t2-t1;


//cout << "the sort took " << time << " mircoseconds." << endl;
cout << time << endl;

}




