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

void      Listi_print(ListNode* l);
ListNode* Listi_read(char* filename);
void      Listi_write(char* filename, ListNode* l);
ListNode* Listi_alloc();
void      Listi_free(ListNode* l);
ListNode* Listi_append(ListNode* src1, ListNode* src2);
int       Listi_compare(ListNode* src1, ListNode* src2);
int       Listi_compare_ordered(ListNode* src1, ListNode* src2);
ListNode* Listi_zeros(int num_elements);
ListNode* Listi_rand(int num_elements, int max_value, int positive_only);
ListNode* Listi_rand_ordered(int num_elements, int max_value, int positive_only);

#endif



