/**
@file main.cpp
@author Warren Scipio */

#include "GeneralTree.h"
#include "Executive.h"

int main(int argc, char* argv[]) {
	if(argc > 1) {
		Executive e(argv[1]);
		
	} else {
		cout << "Please add a file to read" << endl;
	}


	return 0;
}
