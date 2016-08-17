CC=g++
CFLAGS=-c -Wall

all: rshell && mkdir bin

rshell: main.o And.o Command.o Comment.o Component.o Connector.o Or.o Semicolon.o
	$(CC) main.o And.o Command.o Comment.o Component.o Connector.o Or.o Semicolon.o -o rshell

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

And.o: And.cpp And.h
	$(CC) $(CFLAGS) And.cpp

Command.o: Command.cpp Command.h
	$(CC) $(CFLAGS) Command.cpp

Comment.o: Comment.cpp Comment.h
	$(CC) $(CFLAGS) Comment.cpp
	
Component.o: Component.cpp Component.h
	$(CC) $(CFLAGS) Component.cpp
    
Connector.o: Connector.cpp Connector.h
	$(CC) $(CFLAGS) Connector.cpp
    
Or.o: Or.cpp Or.h
	$(CC) $(CFLAGS) Or.cpp

Semicolon.o: Semicolon.cpp Semicolon.h
	$(CC) $(CFLAGS) Semicolon.cpp
    
clean:
	rm *o rshell
