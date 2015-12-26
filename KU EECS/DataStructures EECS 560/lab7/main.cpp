#include "minmaxheap.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	minmaxheap* heap = new minmaxheap("data.txt");

	std::cout << "..........................................................\n" <<
	"Please choose one of the following commands:\n" <<
	"1- insert\n" << 
	"2- remove\n" <<
	"3- deletemin\n" << 
	"4- deletemax\n" << 
	"5- levelorder\n" << 
	"6- exit\n";
	int input;
	std::cin >> input;
	
	while(input != 6){
			if(input == 1){
			std::cout << "Which number would you like to insert?\n";
			std::cin >> input;
			heap->insert(input);
		}else if(input == 2){
			std::cout << "Which number would you like to remove\n";
			std::cin >> input;
			heap->remove(input);
		}else if(input == 3){
			heap->delete_min();
		}else if(input == 4){
			heap->delete_max();
		}else if(input == 5){
			heap->level_order();
		}
		std::cout << "..........................................................\n" <<
		"Please choose one of the following commands:\n" <<
		"1- insert\n" << 
		"2- remove\n" <<
		"3- deletemin\n" << 
		"4- deletemax\n" << 
		"5- levelorder\n" << 
		"6- exit\n";
		std::cin >> input;
	}
		
	
	return 0;
}