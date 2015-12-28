#include "node.cpp"
#include <cstddef>
#include <iostream>

class linked_list
{
private:
	void printHelper(node* l);
	void insertHelper(int x, node* l);
	bool eraseHelper(int x, node* l, node* prev);
	node* findHelper(int x, node* location);
	node* head_ptr;
public:
	linked_list();
	~linked_list();
	void insert(int x);
	bool isEmpty();
	bool erase(int x);
	void print();
	node* find(int x);
};


linked_list::linked_list() {
	head_ptr = nullptr;	
	
}

void linked_list::insert(int x) {
	if(find(x) == nullptr) {
		if(head_ptr == nullptr)
			head_ptr = new node(x);
		else
			insertHelper(x, head_ptr);
	}
}

void linked_list::insertHelper(int x, node* l){
	if(l->getNext() != nullptr)
		insertHelper(x, l->getNext());
	else {
		node* new_node = new node(x);
		l->setNext(new_node);
	}
}

bool linked_list::isEmpty() {
	if(head_ptr == nullptr) {
		return true;
	} else {
		return false;
	}
}

bool linked_list::erase(int x) {
	if(head_ptr != nullptr && find(x) != nullptr){
		if(head_ptr->getItem() != x)
			return eraseHelper(x,head_ptr->getNext(), head_ptr);
		else {
			node* tmp_ptr = head_ptr;
			head_ptr = head_ptr->getNext();
			delete tmp_ptr;
			return false;
		}
	}
}

bool linked_list::eraseHelper(int x, node* l, node* prev) {
	if(l->getItem() == x) {
		prev->setNext(l->getNext());
		delete l;
		return true;
	} else {
		if(l != nullptr)
			eraseHelper(x, l->getNext(), l);
		else
			return false;
	}
}

void linked_list::print() {
	if (head_ptr != nullptr){
		printHelper(head_ptr);
	} 
}

void linked_list::printHelper(node* l) {
	std::cout<< l->getItem() << " ";
	if(l->getNext() != nullptr){
		printHelper(l->getNext());
	}
}

node* linked_list::find(int x) {
	if(head_ptr != nullptr) {
		if(head_ptr->getItem() == x)
			return head_ptr;
		else
			return findHelper(x, head_ptr->getNext());
	} else
		return nullptr;
}

node* linked_list::findHelper(int x, node* cur_ptr) {
	if(cur_ptr != nullptr) {
		if(cur_ptr->getItem() == x) 
			return cur_ptr;
		else 
			return findHelper(x, cur_ptr->getNext());
	} else
		return nullptr;
}

linked_list::~linked_list() {
	while(head_ptr != nullptr) {
		node* tmp_ptr = head_ptr->getNext();
		delete head_ptr;
		head_ptr = tmp_ptr;
	}
}
