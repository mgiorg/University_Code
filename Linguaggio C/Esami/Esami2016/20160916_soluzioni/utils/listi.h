#ifndef _LISTI_H_
#define _LISTI_H_

#ifdef ESERCIZIO_1
#include "../esercizio1/esercizio1.h"
#endif

#ifdef ESERCIZIO_2
#include "../esercizio2/esercizio2.h"
#endif

#ifdef ESERCIZIO_3
#include "../esercizio3/esercizio3.h"
#endif

void      List_print(ListNode* l);
ListNode* List_load(char* filename);
ListNode* List_alloc();
void      List_free(ListNode* l);
int       List_compare(ListNode* src1, ListNode* src2);
int       List_compare_ordered(ListNode* src1, ListNode* src2);
ListNode* List_zeros(int num_elements);
ListNode* List_rand(int num_elements, int max_value, int positive_only);
ListNode* List_rand_ordered(int num_elements, int max_value, int positive_only);

#endif



