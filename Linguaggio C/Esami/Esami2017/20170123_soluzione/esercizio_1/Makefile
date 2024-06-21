CC=gcc
CFLAGS=--std=gnu99 -Wall
LDFLAGS=-lm
OBJECTS=esercizio_1.o
CORR_OBJECTS=matrix_utils.o
TARGET_SRC=test_esercizio_1.c
TARGET=test_esercizio_1

.phony: all clean

all: clean $(CORR_OBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET_SRC) $(CORR_OBJECTS) $(OBJECTS) $(LDFLAGS) -DESERCIZIO_1=1

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET) 
