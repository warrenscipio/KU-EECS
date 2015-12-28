
#ifndef _NODE
#define _NODE

#include <cstddef>
class node
{
private: 
	int item;
	node* next;
public:
	node();
	node(int input);
	void setItem(const int input);
	void setNext(node* next_node_ptr);
	int getItem();
	node* getNext();
}; 







node::node() {
	next = nullptr;
}

node::node(int input){
	next = nullptr;
	item = input;
}

void node::setItem(const int input) {
	item = input;
}

void node::setNext(node* next_node_ptr){
	next = next_node_ptr;
}

int node::getItem() {
	return item;
}

node* node::getNext() {
	return next;
}

#endif
