/**
@Filename main.cpp
@Author Warren Scipio
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Executive.h"

using namespace std;

int main( int argc, char* argv[]){
	
	//if user doesnt run program with atleast 3 files then, informs user they must
	if(argc>=4){
	//creates streams and sets them to files
	ifstream integerFile(argv[2]);
	ifstream charsFile(argv[1]);
	ifstream stringsFile(argv[3]);
	//instance of executive class
	Executive e(charsFile, integerFile, stringsFile);

	e.print();
	//close the streams
	charsFile.close();
	integerFile.close();
	stringsFile.close();

	}else{ 
	cout << endl;
	cout << "Please run with at least 3 Files, the first 3 Files will be used." << endl;
	cout << "The first file should be the CHAR file second should be the INT file" << endl;
	cout << "the third should be the STRING file."<< endl;
	cout << endl;
	}
	return 0;
	
	


} 

