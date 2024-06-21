#include <stdlib.h>
#include <stdio.h>

#include "esercizio3.h"

int find_spots(char* v, int dim, char* word) { return _find_spots(v, dim, word, 0); }

int _find_spots(char* v, int dim, char* word, int index) {
  if(index >= dim) { return 0; }
  return _check_spot(v, dim, word, index) + _find_spots(v, dim, word, index + 1);
}

int _check_spot(char* v, int dim, char* word, int index) {
  if(word[0] == '\0') { return 1; }
  if(index >= dim) { return 0; }
  if(v[index] == '#') { return 0; }
  return _check_spot(v, dim, word + 1, index + 1);  
}
