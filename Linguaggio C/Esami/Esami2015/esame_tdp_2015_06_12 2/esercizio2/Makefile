UTILS_DIR=
LIBS=-lm
CC=c99
CFLAGS=

all: test_esercizio2

test_esercizio2: esercizio2.o test_esercizio2.o
	$(CC) $(CFLAGS) -o test_esercizio2 esercizio2.o test_esercizio2.o $(LIBS)

esercizio.o: esercizio2.c esercizio2.h
	$(CC) $(CFLAGS) -c esercizio2.c

clean:
	rm -rf *.o test_esercizio2
