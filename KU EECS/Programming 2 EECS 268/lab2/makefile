lab2: main.o matrix.o executive.o
	g++ main.o matrix.o executive.o -o lab2

executive.o: executive.cpp executive.h
	g++ -c -g executive.cpp 

polynomail.o: matrix.cpp matrix.h
	g++ -c -g matrix.cpp

main.o: main.cpp
	g++ -c -g main.cpp

clean:
	rm lab2 *.o
