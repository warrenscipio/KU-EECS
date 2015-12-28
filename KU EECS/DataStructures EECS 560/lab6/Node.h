#ifndef Node_H_
#define Node_H_
#include <stddef.h>

template<typename T>
class Node {
 public:
  Node(T k, Node<T>* p);
  Node(T ms, Node<T>* f, Node<T>* s, Node<T>* p);
  Node(T ms, T mt, Node<T>* f, Node<T>* s, Node<T>* t, Node* p);
  T key;
  T tag;
  Node<T>* first;
  Node<T>* second;
  Node<T>* third;
  Node<T>* parent;
  T minSecond;
  T minThird;
  bool isLeaf();
  bool is2Node();
};

template<typename T>
Node<T>::Node(T k, Node<T>* p) :
key(k), tag(1), first(NULL), second(NULL),third(NULL), parent(p), minSecond(-1), minThird(-1) {
}

template<typename T>
Node<T>::Node(T ms, Node<T>* f, Node<T>* s, Node<T>* p) :
key(-1), tag(0), first(f), second(s),third(NULL), parent(p), minSecond(ms), minThird(-1) {
}

template<typename T>
Node<T>::Node(T ms, T mt, Node<T>* f, Node<T>* s, Node<T>* t, Node<T>* p) :
key(-1), tag(0), first(f), second(s),third(t), parent(p), minSecond(ms), minThird(mt) {
}

template<typename T>
bool Node<T>::isLeaf() {
	if(tag != 0)
		return true;
	else
		return false;

}

template<typename T>
bool Node<T>::is2Node() {
	if(third == NULL)
		return true;
	else
		return false;
}


#endif
