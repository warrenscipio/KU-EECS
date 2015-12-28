lab6:	Main.o Executive.o
	g++ Main.o Executive.o -o lab6

Main.o: Main.cpp
	g++ -c -g Main.cpp

Executive.o: Executive.cpp Executive.h 
	g++ -c -g Executive.cpp 

clean:
	rm lab6 *.o
