UTILS_DIR=../utils
LIBS=-lm
CPPC=g++
CPPFLAGS=-Wall

all: test_esercizio2

test_esercizio2: test_esercizio2.c esercizio2.c $(UTILS_DIR)/vec.c $(UTILS_DIR)/list.c
	$(CPPC) $(CPPFLAGS) $(LIBS) test_esercizio2.c esercizio2.c $(UTILS_DIR)/vec.c $(UTILS_DIR)/list.c -o test_esercizio2 -DESERCIZIO_2=1

clean:
	rm -rf *.o test_esercizio2
