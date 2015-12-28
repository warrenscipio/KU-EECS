#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>

int heap[500];
int num_nodes = 0;

bool is_empty(){
	return num_nodes == 0;
}

bool isminlevel(int location) {
	return int(trunc(log2(location+1)))%2==0;
}

void heapify(int loc) {
	std::cout << "location: " << loc << " num_nodes: "<< num_nodes << " data: " << heap[loc] << std::endl;
	int comp = 2*loc+1; // fill in with a default value
	if (2*loc+1 >= num_nodes)
		return;

	for(int i = 1; i <= 2; i++) {
		if (isminlevel(loc)) {
			if (heap[2*loc+i] < heap[comp]) {
				if (2*loc+i < num_nodes) 
					comp = 2*loc+i;
			}
			for(int j = 1; j <= 2; j++) {
				if (heap[2*(2*loc+i)+j] < heap[comp]) {
					if (2*(2*loc+i)+j < num_nodes)
						comp = 2*(2*loc+i)+j;
				}
			}
		} else {
			if (heap[2*loc+i] > heap[comp]) {
				if (2*loc+i < num_nodes) 
					comp = 2*loc+i;
			}
			for(int j = 1; j <= 2; j++) {
				if (heap[2*(2*loc+i)+j] > heap[comp]) {
					if (2*(2*loc+i)+j < num_nodes)
						comp = 2*(2*loc+i)+j;
				}
			}
		}
	}

	if (isminlevel(loc)) {
		if (heap[comp] < heap[loc]) {
			int tmp = heap[loc];
			heap[loc] = heap[comp];
			heap[comp] = tmp;
			heapify(loc);
			heapify((comp-1)/2);
			heapify(comp);
		}
	} else {
		if (heap[comp] > heap[loc]) {
			int tmp = heap[loc];
			heap[loc] = heap[comp];
			heap[comp] = tmp;
			heapify(loc);
			heapify((comp-1)/2);
			heapify(comp);
		}
	}
}


void insert(int x) {
	heap[num_nodes] = x;
	num_nodes++;
	for (int i = (num_nodes-1)/2; i >= 0; i--) {
		heapify(i);
	}
}

bool insert_helper(int x, int parent, int cur_loc) {
	if (isminlevel(cur_loc)) {
		if (x < heap[parent]) {
			heap[cur_loc] = heap[parent];
			insert_helper(x, (parent-1)/2, parent);
		} else {
			heap[cur_loc] = x;
		}
	} else {
		if (x > heap[parent]) {
			heap[cur_loc] = heap[parent];
			insert_helper(x, (parent-1)/2, parent);
		} else {
			heap[cur_loc] = x;
		}
	}
}

void remove(int x) {
	for (int i = 0; i <= num_nodes; i++) {
		if (heap[i] == x) {
			if (i != num_nodes - 1) {
				std::cout << "nope\n";
				heap[i] = heap[num_nodes - 1];
				heap[num_nodes-1] = INT_MAX;
				num_nodes--;
				for (int i = (num_nodes-1)/2; i >= 0; i--) {
					heapify(i);
				}
			} else {
				heap[num_nodes-1] = INT_MAX;
				num_nodes--;
			}
			break;
		}
	}
}

void delete_min() {
	remove(heap[0]);
}

void delete_max() {
	remove(std::max(heap[1], heap[2]));
}

void level_order(){
	if (num_nodes > 0)
		std::cout << heap[0];
	int j = 1;
	int count = 1;
	for(int i = 2; i <= num_nodes; i++){
		if(count == j){
			std::cout << "\n" << heap[i-1] << " ";
			j = j*2;
			count = 1;
		}else{
			count++;
			std::cout << heap[i-1] << " ";
		}
	}
}

bool search(int x) {
	for (int i = 0; i < num_nodes; i++) {
		if (heap[i] == x)
			return true;
	}
	return false;
}


int main(int argc, char* argv[]){




	
	for (int i = 0; i < 500; i++) {
		heap[i] = -1; // need to have a default value
	}
	
	
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
	

	for (int i = num_nodes-1; i >= 0; i--) {
		heapify(i);
	}
	
	
	int input;
	

	while(input != 5){
		
		
		std::cout << std::endl;
		std::cout << "----------------" << std::endl;
		std::cout << "Menu Options"<< std::endl;
		std::cout << "1 insert"<<std::endl;
		std::cout << "2 deletemin"<< std::endl;
		std::cout << "3 deletemax"<< std::endl;
		std::cout << "4 levelorder"<< std::endl;
		std::cout << "5 exit" << std::endl;
		std::cout << "----------------" << std::endl;
		std::cin >> input;
		
		//just because I wanted to seperate things better
		switch (input){
			
			case 1:
				std::cout << "-----insert-----" << std::endl;
				break;
			case 2:
				std::cout << "----deletemin----" << std::endl;
				break;
			case 3:
				std::cout << "----deletemax----" << std::endl;
				break;
			case 4:
				std::cout << "---levelorder----" << std::endl;
				break;
			case 5:
				std::cout << "----------------" << std::endl;
				break;
			default:
				std::cout << "----------------" << std::endl;
				break;
	
				
		}
		
		
		switch (input){
			
			case 1:
				std::cout << "Which number would you like to insert?\n";
				std::cin >> input;
				insert(input);
				break;
			case 2:
				delete_min();
				break;
			case 3:
				delete_max();
				break;
			case 4:
				level_order();
				break;
			case 5:
				std::cout << "good bye" << std::endl;
				break;
			default:
				std::cout << "not an option" <<std::endl;
				break;
	
				
		}
			
	}
	

	return 0;
}








