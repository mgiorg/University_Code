#ifndef _SPARSE_VECTOR_ELEMENT_UTILS_H_
#define _SPARSE_VECTOR_ELEMENT_UTILS_H_

#include "../esercizio3/esercizio3.h"

// loads an array of lists of SparseVectorElementList_print from a file
SparseVectorElement** SparseVectorElementListArray_load(int* size, char* filename);

// prints the a list of SparseVectorElementList_print
void SparseVectorElementList_print(SparseVectorElement* l); 

// compare two lists of SparseVectorElement 
int SparseVectorElementList_compare(SparseVectorElement* l_a, SparseVectorElement* l_b);

#endif
