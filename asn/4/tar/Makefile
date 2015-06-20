
CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= main.cpp functions.cpp LinkedStack.cpp LinkedQueue.cpp ArrayStack.cpp ArrayQueue.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
