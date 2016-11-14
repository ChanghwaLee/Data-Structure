help:
	@echo "make help"
	@echo "make all"


ADT_llist.o: ADT_llist.c
	g++ -c ADT_llist.c

main.o: main.c
	g++ -c main.c

all: ADT_llist.o main.o
	g++ -o llist.exe main.o ADT_llist.o

run: all
	llist.exe	

clean: 
	del *.o

cleanup: clean
	del *.exe

	

