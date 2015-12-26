all:Lab09


Lab09: main.o minmaxheap.o
	g++ minmaxheap.o main.o -o Lab9

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

minmaxheap.o: minmaxheap.cpp
	g++ -c -g -std=c++11 minmaxheap.cpp

clean:
	rm *.o