#Makefile
all: add-nbo

add-nbo: main.o
	g++ main.o -o add-nbo

main.o: main.c

clean:
	rm -f add-nbo
	rm -f *.o
