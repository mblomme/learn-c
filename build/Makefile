CC=gcc
CFLAGS=-g -Wall -O0 -std=c11
SOURCES=../src/*
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=datastructures

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
