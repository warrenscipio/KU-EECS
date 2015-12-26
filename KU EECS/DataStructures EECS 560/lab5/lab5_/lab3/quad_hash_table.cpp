#include <cstddef>
#include <iostream>


class quad_hash_table
{
private:
	int size;
	int counter = 0;
	closed_node* main_list = nullptr;
public:
	quad_hash_table(int i_size);
	~quad_hash_table();
	void insert(int x);
	bool remove(int x);
	void print();
	int hash_add(int x, int i);
	int hash_remove(int x, int i);
	bool contains(int x);
	bool isFull();
};

quad_hash_table::quad_hash_table(int i_size){
	size = i_size;
	main_list = new closed_node[size];
}

quad_hash_table::~quad_hash_table(){
	delete [] main_list;
}

void quad_hash_table::insert(int x){
	if (!isFull()){
		if (!contains(x)) {
			main_list[hash_add(x, 0)].setItem(x);
			counter++;
		}
	}
}

int quad_hash_table::hash_add(int x, int i) {
	if (main_list[(x+(i*i)) % size].isEmpty()) {
		return (x+(i*i)) % size;
	} else {
		return hash_add(x, i+1);
	}
}

int quad_hash_table::hash_remove(int x, int i) {
	if (main_list[(x+(i*i)) % size].isUsed()) {
		if(main_list[(x+(i*i)) % size].getItem() == x){
			return (x+(i*i)) % size;
		} else {
			return hash_remove(x, i+1);	
		}
	} else {
		return -1;
	}
}

bool quad_hash_table::remove(int x){
	int index = hash_remove(x, 0);
	if (index == -1)
		return false;
	else
		main_list[index].removeItem();
}

void quad_hash_table::print(){
	for(int i = 0; i < size; i++){
		std::cout << i << ": ";
		if(!main_list[i].isEmpty())
			std::cout << main_list[i].getItem();
		std::cout << "\n";
	}
}

bool quad_hash_table::contains(int x){
	return hash_remove(x, 0) != -1;
}

bool quad_hash_table::isFull() {
	return counter == size;
}
