/**
@file Main.cpp
@author Warren Scipio */


#include "Executive.h"

int main(int argc, char* argv[]) {
	if(argc > 1) {

	

		ifstream file(argv[1]);
		Executive<int> e(file);
	/* I tryed to get the tree to work for chars and strings but didnt work
		string option = argv[2];
		
		if(option =="ints"){
			Executive<int> e(file);

		}else if(option == "chars" ){
			//Executive<char> e(file);

		}else if(option == "strings"){
			//Executive<string> e(file);

		} else {
			cout << ">>sorry not available, choose one of the three types.. " << endl;
		}
	*/
	

		file.close();
	} else {
		cout << "Please add a file to read and a type" << endl;
	}

	return 0;
}
