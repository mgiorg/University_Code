#ifndef _SPARSE_VECTOR_UTILS_H_
#define _SPARSE_VECTOR_UTILS_H_

#include "../esercizio2/esercizio2.h"

// prints the entire vector (including zeroes) in the form: position, value\n
void SparseVector_print(SparseVector* vec); 

// allocates a sparse vector of dimension dim, with 0 non null values
SparseVector* SparseVector_alloc(int dimension);

// frees a sparse vector deleting the list and area pointed by vec
void SparseVector_free(SparseVector* vec);

// compare two sparse vectors
int SparseVector_compare(SparseVector* vec_a, SparseVector* vec_b);

#endif
