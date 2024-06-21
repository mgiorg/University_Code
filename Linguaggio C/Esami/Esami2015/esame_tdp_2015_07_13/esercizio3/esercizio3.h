#ifndef _ESERCIZIO3_H_
#define _ESERCIZIO3_H_

// element of a sparse vector
typedef struct SparseVectorElement {
  int pos;                    // index in the array
  float value;                // value
  SparseVectorElement* next;  // next ptr
} SparseVectorElement;

// returns l1 + l2. Assumes l1 and l2 are ordered by pos. 
// recursive 
SparseVectorElement* recursiveSum(SparseVectorElement* l1, SparseVectorElement* l2);

#endif
