# Compiler
CC=g++
#CC=gcc

# Compile options
CFLAGS= -g -Wall

# Executable
EXECUTABLE= x-ts

all: x-ts

x-ts: main.o utils.o parser.o
	$(CC) main.o utils.o parser.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

utils.o: utils.cpp
	$(CC) -c $(CFLAGS) utils.cpp	

parser.o: parser.cpp
	$(CC) -c $(CFLAGS) parser.cpp

clean:
	rm -rf *o $(EXECUTABLE)
