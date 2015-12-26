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

Executive::Executive ( char* size, char* data, char* method, char* point) {//1
	threshold = atoi(point);
		
	arraySize = atoi(size);
//this made it so it would print out a col for me so I could copy and paste it to the spread sheet
	/*for(int i=0; i<6;i++){
		//double *array;

		switch(i){

		case 0 :threshold=30;
		break;
		
		case 1 :threshold=100;
		break;

		case 2 :threshold=500;
		break;

		case 3 :threshold=1000;
		break;

		case 4 :threshold=1500;
		break;

		case 5 :threshold=2000;
		break;

		default: cout<< "broke"<<endl;
		break;
		
	}	
*/

		double *array;
		array = new double[arraySize];
		
		
		
		dataOrder(data,array);
		sortMethod(method,array);
	
	//}

}
void Executive::dataOrder(char data[],double array[]){

	string word(data);
 
	//ifs and elses taking in the user input and creating the the array specified
	if(word == "random"){
		srand((unsigned)time(0));

		for(int i=0; i<arraySize;i++)
			array[i] = (rand() % 100000);		
	
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
	//notifies the user the program is still running(or atleast made it this far)
	cout << "sorting method is sorting..." << endl;
	//ifs and elses choosing the correct sorting algorithm
	if(word == "QSIS"){
		time1 = getTime();
		quicksort(array, arraySize,threshold, 0);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);
	
	}else if(word == "QSBS"){

		time1 = getTime();
		quicksort(array, arraySize,threshold, 1);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);

	}else if(word == "MSIS"){

		time1 = getTime();
		mergesort(array, arraySize,threshold, 0);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);

	}else if(word == "MSBS"){

		time1 = getTime();
		mergesort(array, arraySize,threshold, 1);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);

	}else if(word == "merge"){

		time1 = getTime();
		mergesort(array, arraySize,threshold, 2);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);

	}else if(word == "quick"){
	

		time1 = getTime();
		quicksort(array, arraySize,threshold, 2);
		time2 = getTime();
		printTime(time1, time2);
		//printArray(array);


	}else{ 
		//informs user what their options are.
		cout << "Choose a sorting method for the third argument, options:" << endl;
		cout << "MSBS(merge bubble hybrid)" << endl;
		cout << "MSIS(merge insertion hybrid)" << endl;
		cout << "QSBS(quick bubble hybrid)" << endl;
		cout << "QSIS(quick insertion hybrid)" << endl;
		cout << "merge" << endl;
		cout << "quick" << endl;
		exit(0);
	}

	
}



unsigned long Executive::getTime(void)
      {
     	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec*1000000ul +tv.tv_usec;

      }
//short method to view the array before or after it is sorted.
void Executive::printArray(double array[]){

for(int i=0; i<arraySize;i++){
		cout << array[i] << endl;
		}
}

void Executive::printTime(unsigned long t1, unsigned long t2){
unsigned long time = t2-t1;


cout << "the sort took " << time << " mircoseconds." << endl;


}








