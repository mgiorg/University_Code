#include <stdio.h>
#include <stdlib.h>

typedef int TipoInfoSCL;

struct TipoNodoSCL{
	TipoInfoSCL info;
	struct TipoNodoSCL* next;
};

typedef struct TipoNodoSCL* TipoSCL;

void print(TipoSCL list_) {
  if (!list_) {
    return;
  }

  //ds print head
  printf("[%i]", list_->info);
  list_ = list_->next;

  //ds print the rest of the list
  while (list_) {
    printf(" -> [%i]", list_->info);
    list_ = list_->next;
  }
  printf("\n");
}

TipoSCL generate(const int* number_of_nodes_) {
  TipoSCL head = 0;
  
  //ds allocate a list with n elements and random values [0, 10]
  TipoSCL node_previous = 0;
  for (int u = 0; u < number_of_nodes_; ++u) {
    TipoSCL node = new TipoNodoSCL();
    node->info     = rand()%11;

    //ds if the head is not set yet
    if (!head) {
      head = node;
    } else {

      //ds link previous node to this
      node_previous->next = node;
    }
    node_previous = node;
  }
  return head;
}

TipoSCL copySCL(TipoSCL src) {
	TipoSCL head = 0;
	TipoSCL node_previous = 0;
	TipoSCL aux = src;
	while (aux) {
	    TipoSCL node = new TipoNodoSCL();
	    node->info     = aux->info;

	    //ds if the head is not set yet
	    if (!head) {
	      head = node;
	    } else {
              node_previous->next = node;
	    }
	    node_previous = node;
	    aux = aux->next;
	  }
	  return head;
}

void freeSCL(TipoSCL list_) {
  if (!list_) {
    return;
  }
  while (list_) {
    TipoSCL list_next = list_->next;
    delete list_;
    list_ = list_next;
  }
}

TipoSCL generateFromArray(TipoInfoSCL *arr, int len) {
  
  TipoSCL head = NULL;
  
  //ds allocate a list with n elements and random values [0, 10]
  TipoSCL node_previous = 0;
  for (int u = 0; u < len; ++u) {
    TipoSCL node = new TipoNodoSCL();
    node->info     = arr[u];

    //ds if the head is not set yet
    if (!head) {
      head = node;
    } else {

      //ds link previous node to this
      node_previous->next = node;
    }
    node_previous = node;
  }
  return head;
}