lab1: main.o polynomial.o executive.o
	g++ main.o polynomial.o executive.o -o lab1

executive.o: executive.cpp executive.h
	g++ -c -g executive.cpp

polynomail.o: polynomial.cpp polynomial.h
	g++ -c -g polynomial.cpp

main.o: main.cpp
	g++ -c -g main.cpp

clean:
	rm lab1 *.o
