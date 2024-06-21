UTILS_DIR=../utils
LIBS=-lm
CPPC=g++
CPPFLAGS=-Wall

all: test_esercizio3

test_esercizio3: test_esercizio3.c esercizio3.c $(UTILS_DIR)/sparse_vector_element_utils.c
	$(CPPC) $(CPPFLAGS) $(LIBS) test_esercizio3.c esercizio3.c $(UTILS_DIR)/sparse_vector_element_utils.c -o test_esercizio3 

clean:
	rm -rf *.o test_esercizio3
