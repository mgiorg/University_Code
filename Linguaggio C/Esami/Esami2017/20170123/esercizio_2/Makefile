CC=gcc
CFLAGS=--std=gnu99 -Wall
LDFLAGS=-lm
OBJECTS=esercizio_2.o
CORR_OBJECTS=correttore_esercizio_2.o
TARGET_SRC=test_esercizio_2.c
TARGET=test_esercizio_2

.phony: all clean

all: clean $(CORR_OBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET_SRC) $(CORR_OBJECTS) $(OBJECTS) $(LDFLAGS) -DESERCIZIO_2=2

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET) 
