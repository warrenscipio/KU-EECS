#include "BST_node.h"

BST_node::BST_node() {
	left_child = nullptr;
	right_child = nullptr;
}

BST_node::~BST_node() {
	delete left_child;
	delete right_child;
	data = -1;
}

BST_node::BST_node(int x) {
	empty = false;
	data = x;
	left_child = nullptr;
	right_child = nullptr;
}


bool BST_node::is_empty() {
	return empty;
}

BST_node* BST_node::get_left_child() {
	return left_child;
}

BST_node* BST_node::get_right_child() {
	return right_child;
}

bool BST_node::set_left_child(int x) {
	if (left_child == nullptr) {
		BST_node* tmp = new BST_node(x);
		left_child = tmp;
		return true;
	}
	return false;
}

bool BST_node::set_right_child(int x) {
	if (right_child == nullptr) {
		BST_node* tmp = new BST_node(x);
		right_child = tmp;
		return true;
	}
	return false;
}

void BST_node::set_left_child(BST_node* t) {
	left_child = t;
}

void BST_node::set_right_child(BST_node* t) {
	right_child = t;
}

int BST_node::get_data(){
	return data;
}

void BST_node::set_data(int x) {
	data = x;
	empty = false;
}

int BST_node::get_left_child_data() {
	if (left_child != nullptr) {
		return left_child->get_data();
	}
	return -1;
}

int BST_node::get_right_child_data() {
	if (right_child != nullptr) {
		return right_child->get_data();
	}
	return -1;
}