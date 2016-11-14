help:
	@echo "make help"
	@echo "make all"


ADT_queue.o: ADT_queue.c
	g++ -c ADT_queue.c

main.o: main.c
	g++ -c main.c

all: ADT_queue.o main.o
	g++ -o queue.exe main.o ADT_queue.o

run: all
	queue.exe	

clean: 
	del *.o

cleanup: clean
	del *.exe

	

