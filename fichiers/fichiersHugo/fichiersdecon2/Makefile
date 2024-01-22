test_donjon: test.o constructeur.o
	gcc -o test_donjon test.o constructeur.o

test.o: test.c 
	gcc -c test.c 

constructeur.o: constructeur.c
	gcc -c constructeur.c

clean: 
	del /f /q *.o

all: 
	make clean
	make test_donjon