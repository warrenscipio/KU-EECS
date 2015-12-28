/**
@Filename Executive.h
@Author Warren Scipio
*/

#ifndef _EXECUTIVE_
#define _EXECUTIVE_

#include <string>
#include <sys/resource.h>
#include <sys/time.h>
#include "Sorts.h"



using namespace std;
 
class Executive{


public:

	Executive();
	Executive( char size[], char dataOrder[], char method[], char point[]);

	void dataOrder(char data[],double array[]);
	void printArray(double array[]);
	void printTime(unsigned long t1, unsigned long t2);
	void sortMethod(char method[], double array[]);
	unsigned long getTime(void);
	int arraySize;
	int threshold;
	
	
	
	
			

	
	
	
private:
	
		
	
	


};

#endif
