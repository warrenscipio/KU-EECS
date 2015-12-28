/**
@file Executive.cpp
@author Warren Scipio */


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>


template <typename T>
Executive<T>::Executive(){

}
template <typename T>
Executive<T>::Executive (istream& file) {
	
	
	tree = new GeneralTree<T>(file);
	menu();
	tree->getCommands();

}







template <typename T>
void Executive<T>::menu(){
	
	cout << "-------------------------------------------------" << endl;
	cout << "print : prints out the tree" << endl;
	cout << "parent X: finds parent of value of X" << endl; 
	cout << "child  X: finds child of value of X" << endl;
	cout << "sibling X: finds sibling of value of X	" << endl;
	cout << "addfirst X Y: adds the value Y as the first child of X" << endl;
	cout << "addlast X Y: adds the value Y as the last child of X" << endl;
	cout << "remove X: removes value of X from tree" << endl;
	cout << "export X: exports curret tree to file named X" << endl;
	cout << "read X: read from a new file X" << endl;
	cout << "quit: quits program" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl;



}







