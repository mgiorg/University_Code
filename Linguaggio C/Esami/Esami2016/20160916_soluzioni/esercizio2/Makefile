CC=gcc
CFLAGS=--std=gnu99 -Wall
LDFLAGS=-lm
OBJECTS=esercizio2.o
CORR_OBJECTS=correttore_esercizio2.o
UTILS_DIR=../utils
TARGET_SRC=test_esercizio2.c
TARGET=test_esercizio2

.phony: all clean

all: clean $(CORR_OBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET_SRC) $(CORR_OBJECTS) $(OBJECTS) $(UTILS_DIR)/mati_struct.c $(UTILS_DIR)/listi.c $(LDFLAGS) -DESERCIZIO_2=1

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET) 
