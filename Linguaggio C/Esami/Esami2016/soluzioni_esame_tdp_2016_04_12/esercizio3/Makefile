CC=gcc
CFLAGS=--std=gnu99 -Wall
LDFLAGS=-lm
OBJECTS=esercizio3.o
CORR_OBJECTS=correttore_esercizio3.o
UTILS_DIR=../utils
TARGET_SRC=test_esercizio3.c
TARGET=test_esercizio3

.phony: all clean

all: clean $(CORR_OBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET_SRC) $(CORR_OBJECTS) $(OBJECTS) $(UTILS_DIR)/sparse_matrix.c $(LDFLAGS) -DESERCIZIO_3=1

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET) 
