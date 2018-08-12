CC = g++
CCFLAGS = -std=c++14

all: Exe 

Exe : Main.o Node.o Visitor.o Iterator.o

	$(CC) -o Exe Main.o Node.o Visitor.o Iterator.o

Main.o: Main.cpp
	$(CC) $(CCFLAGS) -c Main.cpp

Node.o: Node.cpp
	$(CC) $(CCFLAGS) -c Node.cpp

Visitor.o: Visitor.cpp
	$(CC) $(CCFLAGS) -c Visitor.cpp

Iterator.o: Iterator.cpp
	$(CC) $(CCFLAGS) -c Iterator.cpp

clean:
	rm -rf *o 
