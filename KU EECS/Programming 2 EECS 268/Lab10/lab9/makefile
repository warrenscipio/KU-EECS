lab9:	Main.o Executive.o GeneralTree.o
	g++ Main.o Executive.o GeneralTree.o -o lab9

main.o: Main.cpp
	g++ -c -g -std=c++11 Main.cpp

Executive.o: Executive.cpp Executive.h 
	g++ -c -g -std=c++11 Executive.cpp 

GeneralTree.o: GeneralTree.cpp GeneralTree.h 
	g++ -c -g -std=c++11 GeneralTree.cpp 

clean:
	rm lab9 *.o
