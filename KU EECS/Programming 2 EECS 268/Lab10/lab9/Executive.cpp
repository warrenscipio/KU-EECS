
#include "Executive.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

Executive::Executive(){//1

}//1

Executive::Executive ( char s1[] ) {
	
	//int choose =0;
	menu();
	treeFunctions(s1);
/*
	choose = type();

	if(choose ==1){
		menu();
		treeFunctions(s1);
	} else if(choose==2){
		menu();
		treeFunctions(s1);
	}else if(choose==3){
		menu();
		treeFunctions(s1);
	}*/


}

void Executive::treeFunctions(char s1[]) {

GeneralTree tree(s1);
	tree.getCommands();

}




void Executive::menu(){
	
	cout << "-------------------------------------------------" << endl;
	cout << "print : prints out the tree" << endl;
	cout << "parent X: finds parent of value of X" << endl; 
	cout << "child  X: finds child of value of X" << endl;
	cout << "sibling X: finds sibling of value of X	" << endl;
	cout << "addfirst X Y: adds the value Y as the first child of X" << endl;
	cout << "addlast X Y: adds the value Y as the last child of X" << endl;
	cout << "remove X: removes value of X from tree" << endl;
	cout << "quit: quits program" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl;

	
	


}

int Executive::type(){

	cout << "what type of Items are going in the tree?" << endl;
	cout << "strings" << endl;
	cout << "ints" << endl;
	cout << "chars" << endl;
	cout << endl;
	int x = 0;

	string option;
	
	
	while (x!=1 && x!=2 && x!=3){

		cin >> option;
		if(option =="strings"){
			x = 1;
		}else if(option == "ints" ){
			x =2;
		}else if(option == "chars"){
			x = 3;
		} else {
			cout << " sorry not available, choose one of the three types.. " << endl;
		}
	}
	return x;


}






