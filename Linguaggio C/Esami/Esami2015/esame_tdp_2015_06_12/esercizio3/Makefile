UTILS_DIR=
LIBS=-lm
CC=c99
CFLAGS=

all: test_esercizio3

test_esercizio3: esercizio3.o test_esercizio3.o
	$(CC) $(CFLAGS) -o test_esercizio3 esercizio3.o test_esercizio3.o $(LIBS)

esercizio.o: esercizio3.c esercizio3.h
	$(CC) $(CFLAGS) -c esercizio3.c

clean:
	rm -rf *.o test_esercizio3
