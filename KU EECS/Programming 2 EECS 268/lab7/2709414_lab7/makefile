lab7:	main.o Executive.o
	g++ main.o Executive.o -o lab7

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

Executive.o: Executive.cpp Executive.h 
	g++ -c -g -std=c++11 Executive.cpp 



clean:
	rm lab7 *.o
