UTILS_DIR=../utils
LIBS=-lm
CPPC=g++
CPPFLAGS=-Wall

all: test_esercizio2

test_esercizio2: test_esercizio2.c esercizio2.c $(UTILS_DIR)/sparse_vector_utils.c
	$(CPPC) $(CPPFLAGS) $(LIBS) test_esercizio2.c esercizio2.c $(UTILS_DIR)/sparse_vector_utils.c -o test_esercizio2 

clean:
	rm -rf *.o test_esercizio2
