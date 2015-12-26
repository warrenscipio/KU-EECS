Lab2: main.o Matrix.o Executive.o
	g++ main.o Matrix.o Executive.o -o Lab2

Executive.o: Executive.cpp Executive.h
	g++ -c -g Executive.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c -g Matrix.cpp

main.o: main.cpp
	g++ -c -g main.cpp

clean:
	rm Lab2 *.o
