#include "Binary_search_tree.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	Binary_search_tree* tree = new Binary_search_tree();
	
    std::ifstream infile;
    infile.open ("data.txt");
    int i = 0;
    std::string str;
    
    while(std::getline(infile, str)){
        std::stringstream  lineStream(str);
        int value;
        while(lineStream >> value){
        	tree->insert(value);
        }
    }
    infile.close();
	
	std::cout << "..........................................................\n" <<
	"Please choose one of the following commands:\n" <<
	"1- insert\n" << 
	"2- remove\n" <<
	"3- deletemin\n" << 
	"4- deletemax\n" << 
	"5- preorder\n" <<
	"6- inorder\n" <<
	"7- levelorder\n" << 
	"8- exit\n";
	int input;
	std::cin >> input;
	
	while(input != 8){
		if(input == 1){
			std::cout << "Which number would you like to insert?\n";
			std::cin >> input;
			tree->insert(input);
		}else if(input == 2){
			std::cout << "Which number would you like to remove\n";
			std::cin >> input;
			tree->remove(input);
		}else if(input == 3){
			tree->delete_min();
		}else if(input == 4){
			tree->delete_max();
		}else if(input == 5){
			tree->preorder();
		}else if(input == 6){
			tree->inorder();
		}else if(input == 7){
			tree->levelorder();
		}
		std::cout << "..........................................................\n" <<
		"Please choose one of the following commands:\n" <<
		"1- insert\n" << 
		"2- remove\n" <<
		"3- deletemin\n" << 
		"4- deletemax\n" << 
		"5- preorder\n" <<
		"6- inorder\n" <<
		"7- levelorder\n" << 
		"8- exit\n";
		std::cin >> input;
	}
		
	
	return 0;
}
