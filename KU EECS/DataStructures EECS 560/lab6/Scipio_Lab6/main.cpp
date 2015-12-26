#include <iostream>
#include <fstream>
#include "Two3tree.h"
#include <stdlib.h>



using namespace std;

void menu(){

	
	cout << "----------------" << endl;
	cout << "Menu Options"<< endl;
	cout << "1 insert"<< endl;
	cout << "2 remove"<< endl;
	cout << "3 deletemin"<< endl;
	cout << "4 deletemax"<< endl;
	cout << "5 levelorder"<< endl;
	cout << "6 exit" << endl;
	cout << "----------------" << endl;

}


int main() {

	int numbers = 0;
	ifstream infile;
	infile.open("data.txt");
	string word;

	Two3tree<int>* tree = new Two3tree<int>();

	while (!infile.eof()) {
		getline(infile, word, ' ');
		 cout << word << " ";
		if(tree->checkDublicate(atoi(word.c_str())))
			++numbers;
			//cout<< "number inserted"<<endl;
		//else
			//cout<< "no dublicate numbers" <<endl;
	}
	cout << numbers << " numbers inserted."<<endl;
	infile.close();
	
	int value;
	int option= 0;
	
	while(option!=6){
	
	menu();
	cin >> option;
	
		switch(option) {
	
			case 1:
				cout << "Value for insertion: ";
				cin >> value;
				if(tree->checkDublicate(value))
					cout<< "number inserted"<<endl;
				else
					cout<< "no dublicate numbers" <<endl;
				
				break;
			case 2:
				cout << "Value for deletion: ";
				cin >> value;
				//if(check if value is in tree){
				//	tree->delete(value);
				//	cout << value << " deleted";
				//}else
				//	cout << value << " is not in the tree.";
				break;
			case 3:
				//tree->deletemin();
				break;
			case 4:
				//tree->deletemax();
				break;
			case 5:
				tree->levelOrder();
				break;
			case 6:
				cout<< "good-bye" << endl;
				break;
			default:
				cout<< "not an option" <<endl;
				break;
		
	
	
		}
	}
	
	cout << "---------------------------------------" << endl;

	delete tree;


	return 0;
}
