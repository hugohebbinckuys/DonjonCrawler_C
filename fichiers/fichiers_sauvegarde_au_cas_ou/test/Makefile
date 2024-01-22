test_donjon: test.o constructeur_bon.o
	gcc -o test_donjon test.o constructeur_bon.o

test.o: test.c 
	gcc -c test.c 

constructeur_bon.o: constructeur_bon.c
	gcc -c constructeur_bon.c

clean: 
	del /f /q *.o

all: 
	make clean
	make test_donjon