CC = g++
CCFLAGS = -std=c++14

all: Exe 

Exe : Main.o Node.o

	$(CC) -o Exe Main.o Node.o

Main.o: Main.cpp
	$(CC) $(CCFLAGS) -c Main.cpp

Node.o: Node.cpp
	$(CC) $(CCFLAGS) -c Node.cpp

clean:
	rm -rf *o Main.o Node.o
