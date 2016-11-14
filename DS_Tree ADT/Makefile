help:
	@echo "make help"
	@echo "make all"


ADT_tree.o: ADT_tree.c
	g++ -c ADT_tree.c

main.o: main.c
	g++ -c main.c

all: ADT_tree.o main.o
	g++ -c ADT_tree.c
	g++ -c main.c
	g++ -o tree.exe main.o ADT_tree.o

run: all
	tree.exe	

clean: 
	del *.o

cleanup: clean
	del *.exe

	

