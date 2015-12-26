#include <cstddef>

class closed_node
{
private: 
	int item = 0;
	bool used = false;
	bool empty = true;
public:
	closed_node();
	closed_node(int input);
	void setItem(const int input);
	bool isUsed();
	int getItem();
	void removeItem();
	bool isEmpty();
	
};	

closed_node::closed_node() {
	used = false;
	empty = true;
}

closed_node::closed_node(int input){
	item = input;
	empty = false;
	used = true;
}

void closed_node::setItem(const int input) {
	item = input;
	empty = false;
	used = true;
}

void closed_node::removeItem() {
	item = 0;
	empty = true;
}

int closed_node::getItem() {
	return item;
}

bool closed_node::isUsed(){
	return used;
}

bool closed_node::isEmpty() {
	return empty;
}


