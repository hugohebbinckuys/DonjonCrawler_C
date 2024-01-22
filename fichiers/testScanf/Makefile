exo: test.o
	gcc -o exo test.o

test.o: test.c 
	gcc -c test.c 

clean: 
	del /f /q *.o

all: 
	make clean
	make exo