UTILS_DIR=../utils
LIBS=-lm
CPPC=g++
CPPFLAGS=-Wall

all: test_esercizio1

test_esercizio1: test_esercizio1.c esercizio1.c $(UTILS_DIR)/image_utils.c
	$(CPPC) $(CPPFLAGS) $(LIBS) test_esercizio1.c esercizio1.c $(UTILS_DIR)/image_utils.c -o test_esercizio1 

clean:
	rm -rf *.o test_esercizio1
