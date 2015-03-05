CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=main.cpp List.cpp Tree.cpp Writer.cpp Read.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=huffman

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
