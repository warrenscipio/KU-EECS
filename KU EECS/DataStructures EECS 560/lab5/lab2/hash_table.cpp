#include <cstddef>
#include <iostream>
#include "linked_list.cpp"


class hash_table
{
private:
	int size;
	linked_list* main_list = nullptr;
public:
	hash_table(int i_size);
	~hash_table();
	void insert(int x);
	bool remove(int x);
	void print();
	int hash(int x);
	bool find(int x);
};




hash_table::hash_table(int i_size){
	size = i_size;
	main_list = new linked_list[size];

}

hash_table::~hash_table(){
	delete [] main_list;
}

void hash_table::insert(int x){
	main_list[hash(x)].insert(x);
}

int hash_table::hash(int x){
	return x % size;
}

bool hash_table::remove(int x){
	return main_list[hash(x)].erase(x);
}

void hash_table::print(){
	for(int i = 0; i < size; i++){
		std::cout << i << ": ";
		main_list[i].print();
		std::cout << "\n";
	}
}

bool hash_table::find(int x){
	if(main_list[hash(x)].find(x) != nullptr)
		return true;
	else
		return false;
}

