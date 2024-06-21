#ifndef _ESERCIZIO2_H_
#define _ESERCIZIO2_H_

// element of a sparse vector
typedef struct SparseVectorElement {
  int pos;                    // index in the array
  float value;                // value
  SparseVectorElement* next;  // next ptr
} SparseVectorElement;

typedef struct SparseVector {
  int dimension;               // dimension
  SparseVectorElement* values; // unordered list of non zero values
} SparseVector;

// returns the list element at pos. NULL if no element is in pos
SparseVectorElement** SparseVector_getElemAt(SparseVector* vec, int pos);

// returns the value at pos. If the value is not in the list it returns 0
float SparseVector_getElem(SparseVector* vec, int pos);

// sets the value at position pos.
// if the value is 0 and in vec there is an element at pos, it removes it
// if the value is non 0 and in vec there is an element at pos, it replaces the value
// otherwise it adds the element to the vector
// return 0 if pos exceeds the vector dimension, 1 otherwise
int SparseVector_setElem(SparseVector* vec, int pos, float value);

#endif
