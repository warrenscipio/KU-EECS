all:lab5

lab5: main.o Queue.o BST_node.o Binary_search_tree.o
	g++ Queue.o BST_node.o Binary_search_tree.o main.o -o lab5

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

Queue.o: Queue.cpp
	g++ -c -g -std=c++11 Queue.cpp

BST_node.o: BST_node.cpp
	g++ -c -g -std=c++11 BST_node.cpp

Binary_search_tree.o: Binary_search_tree.cpp
	g++ -c -g -std=c++11 Binary_search_tree.cpp

clean:
	rm *.o
