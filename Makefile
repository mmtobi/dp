CC = g++
CCFLAGS = -std=c++14

all: Dp 

Dp: Main.o Node.o Visitor.o Iterator.o Command.o
	$(CC) -o Dp Main.o Node.o Visitor.o Iterator.o Command.o

Main.o: Main.cpp
	$(CC) $(CCFLAGS) -c Main.cpp

Node.o: Node.cpp
	$(CC) $(CCFLAGS) -c Node.cpp

Visitor.o: Visitor.cpp
	$(CC) $(CCFLAGS) -c Visitor.cpp

Iterator.o: Iterator.cpp
	$(CC) $(CCFLAGS) -c Iterator.cpp

Command.o: Command.cpp
	$(CC) $(CCFLAGS) -c Command.cpp

clean:
	rm -rf *o 
