/**
@file GeneralTree.cpp
@author Warren Scipio */


template <typename T>
GeneralTree<T>::GeneralTree() {
	rootPtr = nullptr;
}
template <typename T>
GeneralTree<T>::GeneralTree(istream& file) {
	
	char c;
	file >> c;
	T i;
	file >> i;
	rootPtr = new BinaryNode<T>(i);
	buildTree(file, rootPtr);
	
}
template <typename T>
void GeneralTree<T>::getCommands() {
	bool done = false;
	while(!done && rootPtr != nullptr) {
		cout << "Please input a command. For a list of commands type help." << endl;

		string s;
		cin >> s;

		if(s == "print") {
			cout << endl;
			printTree(rootPtr, "");
			cout << endl;
		} else if(s == "export") {

			cout << "Please input file name" << endl;
			string f;
			cin >> f;
			ofstream out(f);
			exportTree(out, rootPtr);
		} else if(s == "parent") {
			T i;
			cin >> i;
			cout << endl;
			bool boo = false;
			bool b = findParent(i, rootPtr, boo);
			if(!boo) {
				cout << "There are no nodes with a child with that value." << endl << endl;
			} else {
				cout << "are the parents of " << i << endl << endl;
			}
		} else if(s == "child") {
			T i;
			int aoo=0;
			
			cin >> i;
			cout << endl;
			bool boo;
			 boo = false;
			findChild(i, rootPtr, boo, aoo);
			if(aoo<1) {
				cout << "There are no nodes with that value with children." << endl << endl;
			} else {
				cout << "are all of the children of " << i << endl << endl;
			}
		} else if(s == "siblings") {
			T i;
			 
			cin >> i;
			int j = 0;			
			cout << endl;
			findSiblings(i, rootPtr, j);
			if(j > 0) {
				cout << "are all of the siblings of " << i << endl << endl;
			} else {
				cout << "There are no nodes with that value with siblings." << endl << endl;
			}
		} else if(s == "addfirst") {
			T i, j;
			cin >> i;
			cin >> j;
			cout << endl;
			bool boo = false;
			if(i != j) {
				addFirst(i, j, rootPtr, boo);
				if(!boo) {
					cout << "There are no nodes with the value " << i << endl << endl;
				}
			} else {
				cout << "The two values cannot equal each other" << endl << endl;
			}
		} else if(s == "addlast") {
			T i, j;
			cin >> i;
			cin >> j;
			cout << endl;
			bool boo = false;
			if(i != j) {
				addLast(i, j, rootPtr, boo);
				if(!boo) {
					cout << "There are no nodes with the value " << i << endl << endl;
				}
			} else {
				cout << "The two values cannot equal each other" << endl << endl;
			}
		} else if(s == "remove") {
			T i;
			cin >> i;
			cout << endl;
			bool boo = false;
			try {
				removeNode(i, rootPtr, boo);
				if(!boo) {
					cout << "There are no nodes with the value " << i << endl << endl;
				}
			} catch (exception e) {
				cerr << e.what() << endl;
			}
		} else if(s == "quit") {
			done = true;
		

		}else if(s=="read"){
			string name;
			cin >> name;
			cout << endl;
			ifstream inp(name);
			read(inp);
		
		} else {
			cout << "Please add a proper command" << endl << endl;
		}
	}
	if(rootPtr == nullptr){
		cout << "tree is empty" <<endl;
	}
	
}

template <typename T>
void GeneralTree<T>::read(istream& file) {
	
	char c;
	file >> c;
	T i;
	file >> i;
	rootPtr = new BinaryNode<T>(i);
	buildTree(file, rootPtr);
	
}



template <typename T>
void GeneralTree<T>::buildTree(istream& inp, BinaryNode<T>* n) {
	char p;
	if(inp >> p) {
		if(p == '(') {
			T i;
			inp >> i;
			BinaryNode<T>* m = new BinaryNode<T>(i);
			n -> setLeftChildPtr(m);
			buildTree(inp, m);
			while(inp >> p) {
				if(p == '(') {
					inp >> i;
					BinaryNode<T>* o = new BinaryNode<T>(i);
					m -> setRightChildPtr(o);
					buildTree(inp, o);
					m = o;
				}else {
					break;
				}
			}
		}			
	}	
}
template <typename T>
void GeneralTree<T>::printTree(BinaryNode<T>* n, string s) const {
	if(n != nullptr) {		
		T i = n -> getItem();
		string p = s + to_string(i);
		
		cout << p << endl;
	
		printTree(n -> getLeftChildPtr(), s + "	");
		printTree(n -> getRightChildPtr(), s);	
	}
}




template <typename T>
void GeneralTree<T>::exportTree(ostream& output, BinaryNode<T>* n) const {
	if(n != nullptr) {
		if(n != rootPtr) {
			output << " (" << n -> getItem();
			exportTree(output, n -> getLeftChildPtr());
			output << ")";
			exportTree(output, n -> getRightChildPtr());
		} else {
			output << "(" << n -> getItem();
			exportTree(output, n -> getLeftChildPtr());
			output << ")";
		}
	}
}
template <typename T>
bool GeneralTree<T>::findParent(T i, BinaryNode<T>* n, bool& boo) const {
	if(n != nullptr) {	
		bool a = findParent(i, n -> getLeftChildPtr(), boo);
		bool b = findParent(i, n -> getRightChildPtr(), boo);
			
		if(a) {
			cout << n -> getItem() << endl;
		}
		if(b) {
			return true;
		}
		if(i == n-> getItem() && n != rootPtr) {
			boo = true;
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
template <typename T>
void GeneralTree<T>::findChild(T i, BinaryNode<T>* n, bool& boo, int& aoo) const {
	if(n != nullptr) {
		if(!boo) {
			if(i == n -> getItem()) {
				boo = true;
				if(n-> getLeftChildPtr() != nullptr) {
					aoo++;
			
			}
				cout << endl << "Set" << aoo << ";" << endl;
			}
			findChild(i, n -> getLeftChildPtr(), boo, aoo);
			findChild(i, n -> getRightChildPtr(), boo, aoo);
		} else {
			cout << n -> getItem() << endl;
			
			findChild(i, n -> getRightChildPtr(), boo, aoo);
			findChild(i, n -> getLeftChildPtr(), boo, aoo);
		}
	} else {
		boo = false;
	}
}
template <typename T>
void GeneralTree<T>::findSiblings(T i, BinaryNode<T>* n, int& j)const {
	if(n != nullptr) {
		BinaryNode<T>* m = n -> getLeftChildPtr();
		while(m != nullptr && m -> getItem() != i) {
			m = m -> getRightChildPtr();
		}
		if(m != nullptr) {
			BinaryNode<T>* o = n -> getLeftChildPtr();
			if(o != m) {
				j++;
				cout << "Set " << j << ":" << endl;
				while(o != nullptr) {
					if(o != m) {
						cout << o -> getItem() << endl;
					}
					o = o -> getRightChildPtr();
				}
				cout << endl;
			} else {
				if(m -> getRightChildPtr() != nullptr) {
					j++;
					cout << "Set " << j << ":" << endl;
					while(o != nullptr) {
						if(o != m) {
							cout << o -> getItem() << endl;
						}
						o = o -> getRightChildPtr();
					}
					cout << endl;
				}
			}
		}
		findSiblings(i, n -> getLeftChildPtr(), j);
		findSiblings(i, n -> getRightChildPtr(), j);
	}
			
}
template <typename T>
void GeneralTree<T>::addFirst(T i, int j, BinaryNode<T>* n, bool& boo)const {
	if(n != nullptr) {
		if(n -> getItem() == i) {
			boo = true;
			BinaryNode<T>* m = n -> getLeftChildPtr();
			BinaryNode<T>* o = new BinaryNode<T>(j);
			n -> setLeftChildPtr(o);
			o -> setRightChildPtr(m);
		}
		addFirst(i, j, n -> getLeftChildPtr(), boo);
		addFirst(i, j, n -> getRightChildPtr(), boo);
	}
}
template <typename T>
void GeneralTree<T>::addLast(T i, int j, BinaryNode<T>* n, bool& boo)const {
	if(n != nullptr) {
		if(n -> getItem() == i) {
			boo = true;
			if(n -> getLeftChildPtr() != nullptr) {
				BinaryNode<T>* o = n -> getLeftChildPtr();
				while(o -> getRightChildPtr() != nullptr) {
					o = o -> getRightChildPtr();
				}
			BinaryNode<T>* m = new BinaryNode<T>(j);
			o -> setRightChildPtr(m);
			} else {
				BinaryNode<T>* m = new BinaryNode<T>(j);
				n -> setLeftChildPtr(m);
			}
		}
		addLast(i, j, n -> getLeftChildPtr(), boo);
		addLast(i, j, n -> getRightChildPtr(), boo);
	}
}
template <typename T>
void GeneralTree<T>::removeNode(T i, BinaryNode<T>* n, bool& boo) throw (exception) {
	if(i == rootPtr->getItem() && n -> getLeftChildPtr() == nullptr && n == rootPtr) {
		delete n;
	} else if (i == rootPtr->getItem() && n -> getLeftChildPtr() != nullptr && n == rootPtr) {
		throw invalid_argument("Can't remove the root of the tree unless it is empty.");
	}
	else if(n != nullptr) {
		if(n -> getRightChildPtr() != nullptr) {
			if(n -> getRightChildPtr() -> getItem() == i) {
				boo = true;
				BinaryNode<T>* m = n -> getRightChildPtr() -> getLeftChildPtr();
				if(m != nullptr) {
					BinaryNode<T>* o = m;
					while(o -> getRightChildPtr() != nullptr) {
						o = o -> getRightChildPtr();
					}
					o -> setRightChildPtr(n -> getRightChildPtr() -> getRightChildPtr());
				}else {
					m = n -> getRightChildPtr() -> getRightChildPtr();
				}
				delete n -> getRightChildPtr();
				n -> setRightChildPtr(m);
			}
		}
		if(n -> getLeftChildPtr() != nullptr) {
			if(n -> getLeftChildPtr() -> getItem() == i) {
				boo = true;
				BinaryNode<T>* m = n -> getLeftChildPtr() -> getLeftChildPtr();
				if(m != nullptr) {
					BinaryNode<T>* o = m;
					while(o -> getRightChildPtr() != nullptr) {
						o = o -> getRightChildPtr();
					}
					o -> setRightChildPtr(n -> getLeftChildPtr() -> getRightChildPtr());
				}else {
					m = n -> getLeftChildPtr() -> getRightChildPtr();
				}
				delete n -> getLeftChildPtr();
				n -> setLeftChildPtr(m);
			}
		}
		removeNode(i, n -> getLeftChildPtr(), boo);
		removeNode(i, n -> getRightChildPtr(), boo);
	}
	
}
