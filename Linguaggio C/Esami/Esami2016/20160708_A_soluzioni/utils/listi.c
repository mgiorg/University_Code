#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "listi.h"

void Listi_print(ListNode* l) {
  while(l != NULL) {
    printf("%d ", l->value);
    if(l->next != NULL) {
      printf("-> ");
    }
    l = l->next;
  }
  printf("\n");
}

ListNode* Listi_read(char* filename) {
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  ListNode* gen_node = Listi_alloc();
  gen_node->next = NULL;
  ListNode* list = gen_node;
  while(fscanf(f, "%s", buffer) == 1) {
    list->next = Listi_alloc();
    list = list->next;
    list->value = atoi(buffer);
    list->next = NULL;
  }
  list = gen_node->next;
  free(gen_node);

  fflush(f);
  fclose(f);
  
  return list;
}

void Listi_write(char* filename, ListNode* l) {
  FILE* f = fopen(filename, "w");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  while(l != NULL) {
    fprintf(f, "%d ", l->value);
    l = l->next;    
  }

  fflush(f);
  fclose(f);
}

ListNode* Listi_alloc() {
  return (ListNode*)calloc(1, sizeof(ListNode));
}

void Listi_free(ListNode* l) {
  while(l != NULL) {
    ListNode* tmp = l;
    l = l->next;
    free(tmp);
  }
}

ListNode* Listi_append(ListNode* src1, ListNode* src2) {
  ListNode* gen_node = Listi_alloc();
  gen_node->next = NULL;
  ListNode* list = gen_node;

  while(src1 != NULL) {
    list->next = Listi_alloc();
    list = list->next;
    list->value = src1->value;
    list->next = NULL;
    src1 = src1->next;
  }

  while(src2 != NULL) {
    list->next = Listi_alloc();
    list = list->next;
    list->value = src2->value;
    list->next = NULL;
    src2 = src2->next;
  }
  

  list = gen_node->next;
  free(gen_node);
  
  return list;
}


int Listi_compare(ListNode* src1, ListNode* src2) {
  if(src1 == NULL && src2 != NULL) {
    return 0;
  }
  if(src1 != NULL && src2 == NULL) {
    return 0;
  }
  while(src1 != NULL) {
    ListNode* src2_it = src2;
    int found = 0;
    while(src2_it != NULL) {
      if(src1->value == src2_it->value) {
	found = 1;
	break;
      }
      src2_it = src2_it->next;
    }
    if(!found) { return 0; }
    src1 = src1->next;
  }
  
  return 1;
}

int Listi_compare_ordered(ListNode* src1, ListNode* src2) {
  while(src1 != NULL && src2 != NULL) {
    if(src1->value != src2->value) { return 0; }
    src1 = src1->next;
    src2 = src2->next;
  }
  if(src1 != NULL || src2 != NULL) { return 0; }

  return 1;
}

ListNode* Listi_zeros(int num_elements) {
  ListNode* gen_node = Listi_alloc();
  gen_node->next = NULL;
  ListNode* list = gen_node;
  for(int i = 0; i < num_elements; ++i) {
    list->next = Listi_alloc();
    list = list->next;
    list->value = 0;
    list->next = NULL;
  }
  list = gen_node->next;
  free(gen_node);

  return list;
}


ListNode* Listi_rand(int num_elements, int max_value, int positive_only) {
  ListNode* gen_node = Listi_alloc();
  gen_node->next = NULL;
  ListNode* list = gen_node;
  for(int i = 0; i < num_elements; ++i) {
    int rnd = 0.0f;
    if(positive_only) {
      rnd = rand() % max_value;
    }
    else {
      rnd = (rand() % (2 * max_value)) - max_value;
    }
    list->next = Listi_alloc();
    list = list->next;
    list->value = rnd;
    list->next = NULL;
  }
  list = gen_node->next;
  free(gen_node);

  return list;
}

ListNode* Listi_rand_ordered(int num_elements, int max_value, int positive_only) {
  ListNode* gen_node = Listi_alloc();
  gen_node->next = NULL;
  ListNode* list = gen_node;
  int previous_rnd = 0;
  for(int i = 0; i < num_elements; ++i) {
    int rnd = 0;
    if(positive_only) {
      if(i == 0) {
	rnd = rand() % max_value;
      }
      else {
	rnd = previous_rnd + (rand() % max_value);
      }
    }
    else {
      if(i == 0) {
	rnd = (rand() % (2 * max_value)) - max_value * (int)(num_elements / 2);      
      }
      else {
	rnd = previous_rnd + max_value + ((rand() % (2 * max_value)) - max_value);      
      }
    }
    list->next = Listi_alloc();
    list = list->next;
    list->value = rnd;
    list->next = NULL;
    previous_rnd = rnd;
  }
  list = gen_node->next;
  free(gen_node);

  return list;
}
