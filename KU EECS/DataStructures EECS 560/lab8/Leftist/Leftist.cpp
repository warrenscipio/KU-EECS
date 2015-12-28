#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>


int num_nodes = 0;

bool is_empty(){
	return num_nodes == 0;
}


void insert(int x) {
	
}


void remove(int x) {
	
}

void delete_min() {
	
}

void preorder() {

}

void inorder(){

}

void level_order(){
	
}

bool search(int x) {
	
}


int main(int argc, char* argv[]){


	
	std::ifstream infile;
	infile.open("data.txt");
	std::string word;

	while (!infile.eof()) {
		std::getline(infile, word, ' ');
	
		std::cout << word << " ";
		heap[num_nodes] = atoi(word.c_str());
			num_nodes++;

	}

	infile.close();	
	
	
	
	int input;
	

	while(input != 5){
		
		
		std::cout << std::endl;
		std::cout << "----------------" << std::endl;
		std::cout << "Menu Options"<< std::endl;
		std::cout << "1 insert"<<std::endl;
		std::cout << "2 deletemin"<< std::endl;
		std::cout << "3 preorder"<< std::endl;
		std::cout << "4 inorder"<< std::endl;
		std::cout << "5 levelorder"<< std::endl;
		std::cout << "6 exit" << std::endl;
		std::cout << "----------------" << std::endl;
		std::cin >> input;
		
		
		switch (input){
			
			case 1:
				std::cout << "-----insert-----" << std::endl;
				std::cout << "Which number would you like to insert?\n";
				std::cin >> input;
				insert(input);
				break;
			case 2:
				std::cout << "----deletemin----" << std::endl;
				delete_min();
				break;
			case 3:
				//preorder
				break;
				
			case 4:
				//inorder	
				break;	
			case 5:
				std::cout << "---levelorder----" << std::endl;
				level_order();
				break;
			case 6:
				std::cout << "----------------" << std::endl;
				std::cout << "good bye" << std::endl;
				break;
			default:
				std::cout << "----------------" << std::endl;
				std::cout << "not an option" <<std::endl;
				break;
	
				
		}
			
	}
	

	return 0;
}








