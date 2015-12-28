#include "Binary_search_tree.h"

Binary_search_tree::Binary_search_tree() {
	root = nullptr;
}

bool Binary_search_tree::is_empty() {
	return (num_nodes == 0);
}

void Binary_search_tree::insert(int x) {
	if (search(x) == nullptr) {
		if (root == nullptr) 
			root = new BST_node(x);
		else 
			insert_helper(x, root);
		num_nodes++;
	}
}

void Binary_search_tree::insert_helper(int x, BST_node* t) {
	if (x >= t->get_data()) {
		if (!t->set_right_child(x))
			insert_helper(x, t->get_right_child());
	} else {
		if (!t->set_left_child(x))
			insert_helper(x, t->get_left_child());
	}
}

void Binary_search_tree::preorder() {
	preorder_helper(root);
	std::cout << "\n";
}

void Binary_search_tree::preorder_helper(BST_node* t) {
	if (t != nullptr) {
		std::cout << t->get_data() << " ";
		preorder_helper(t->get_left_child());
		preorder_helper(t->get_right_child());
	}
}

void Binary_search_tree::inorder() {
	inorder_helper(root);
	std::cout << "\n";
}

void Binary_search_tree::inorder_helper(BST_node* t) {
	if (t != nullptr) {
		inorder_helper(t->get_left_child());
		std::cout << t->get_data() << " ";
		inorder_helper(t->get_right_child());
	}
}

BST_node* Binary_search_tree::search(int x) {
	return search_helper(x, root);
}

BST_node* Binary_search_tree::search_helper(int x, BST_node* t) {
	if (t != nullptr){
		if (x > t->get_data()) {
			search_helper(x, t->get_right_child());
		} else if (x < t->get_data()) {
			search_helper(x, t->get_left_child());
		} else {
			return t;
		}
	} else{
		return t;
	}
}

void Binary_search_tree::remove(int x) {
	remove_helper(x, root, nullptr);
}

void Binary_search_tree::remove_helper(int x, BST_node* t, BST_node* p) {
	if (t != nullptr){
		if (x > t->get_data()) {
			remove_helper(x, t->get_right_child(), t);
		} else if (x < t->get_data()) {
			remove_helper(x, t->get_left_child(), t);
		} else {
			remover(t, p);
		}
	}
}

void Binary_search_tree::remover(BST_node* t, BST_node* p) {
	if (t->get_left_child() == nullptr) {
		if (t->get_right_child() == nullptr) {
			if (t->get_data() < p->get_data()) {
				delete t;
				p->set_left_child(nullptr);
			} else { 
				delete t;
				p->set_right_child(nullptr);
			}
		} else {
			t->set_data(get_min(t->get_right_child())->get_data());
			remove_helper(get_min(t->get_right_child())->get_data(), t->get_left_child(), t);
			remove_helper(get_min(t->get_right_child())->get_data(), t->get_right_child(), t);
		}
	} else {
		t->set_data(get_max(t->get_left_child())->get_data());
		remove_helper(get_max(t->get_left_child())->get_data(), t->get_left_child(), t);
		remove_helper(get_max(t->get_left_child())->get_data(), t->get_right_child(), t);
	}
}

BST_node* Binary_search_tree::get_min(BST_node* t) {
	if (t->get_left_child() != nullptr)
		get_min(t->get_left_child());
	else
		return t;
}

BST_node* Binary_search_tree::get_max(BST_node* t) {
	if (t->get_right_child() != nullptr)
		get_max(t->get_right_child());
	else
		return t;
}

void Binary_search_tree::delete_min() {
	remove(get_min(root)->get_data());
}

void Binary_search_tree::delete_max() {
	remove(get_max(root)->get_data());
}

void Binary_search_tree::levelorder() {
	Queue* que = new Queue();
	que->push(root);
	while(!que->is_empty()) {
		std::cout << que->peek()->get_data() << " ";
		if(que->peek()->get_left_child() != nullptr)
			que->push(que->peek()->get_left_child());
		if(que->peek()->get_right_child() != nullptr)
			que->push(que->peek()->get_right_child());
		que->pop();
	}
}
