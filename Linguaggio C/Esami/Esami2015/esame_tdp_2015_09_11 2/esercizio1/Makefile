UTILS_DIR=../utils
LIBS=-lm
CPPC=g++
CPPFLAGS=-Wall

all: test_esercizio1

test_esercizio1: test_esercizio1.c esercizio1.c $(UTILS_DIR)/mat.c
	$(CPPC) $(CPPFLAGS) $(LIBS) test_esercizio1.c esercizio1.c $(UTILS_DIR)/mat.c -o test_esercizio1 -DESERCIZIO_1=1

clean:
	rm -rf *.o test_esercizio1
