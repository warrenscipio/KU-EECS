#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

Executive::Executive(){

}

Executive::Executive ( char file[] ) {
	string word;
	int count = 0;
	
	
	ifstream inp(file);

	
	while (inp >> word ){
		switch(word) {
			case "done":	done();
					break;

			case "show":	show();
					break;
		
			default: addWord(word);
					break; 	

		}
	
		// set each string in text file to string array to use in ADT
	
	}
	inp.close();


}




void Executive::show(){

}





void Executive::done(){

}



void Executive::addWord(string w){
	string c;
	c = w.substr(0,3)
	if(c.compare("VIP")){	
		addToStack(w);
	}else{
		addToQueue(w);
	}

}


void Executive::addToStack(string w){
	if(stack.isEmpty){

	}else{


	}

}

void Executive::addToQueue(string w){


}

	

	
	


	

