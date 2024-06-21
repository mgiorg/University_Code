UTILS_DIR=../utils
LIBS=-lm
CC=c99
CFLAGS=

all: test_esercizio1

test_esercizio1: matrix.o esercizio1.o test_esercizio1.o
	$(CC) $(CFLAGS) -o test_esercizio1 matrix.o esercizio1.o test_esercizio1.o $(LIBS)

esercizio.o: esercizio1.c esercizio1.h
	$(CC) $(CFLAGS) -c esercizio1.c

matrix.o: $(UTILS_DIR)/matrix.c $(UTILS_DIR)/matrix.h
	$(CC) $(CFLAGS) -c $(UTILS_DIR)/matrix.c

clean:
	rm -rf *.o test_esercizio1
