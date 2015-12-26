quash: quash.o
	gcc quash.o -o quash -lreadline
	
main.o: quash.c
	gcc -c -g quash.c -lreadline

clean:
	rm -f *.o quash
