#include "esercizio_2.h"
#include <stdlib.h>
#include <stdio.h>

NodoSCL* cercaNodo(NodoSCL* root, int value){
  NodoSCL* valueNode = root;
  while ( valueNode != NULL ) {
    if(valueNode->value == value)
      {
	return valueNode;
      }
    else
      valueNode = valueNode->next;
  }
  return NULL;
}

void aggiungiNodo(NodoSCL* root, NodoSCL* tail){
  if(root->count == 0){
    *root = *tail;
  }else{    
    NodoSCL* currentNode = root;
    while (currentNode->next) {
      currentNode = currentNode->next;
    }
    currentNode->next = tail;
  }

}


NodoSCL* computeFrequencies(int* v, int v_dim){
  NodoSCL* root = (NodoSCL*)malloc(sizeof(NodoSCL));
  root->next = NULL;
  root->count=0;
  root->value=0;
  
  for(int i=0; i<v_dim; i++){
    int curr_value = v[i];
    NodoSCL* node = cercaNodo(root, curr_value);

    if(node != NULL){
      node->count++;
    }
    else{
      node = (NodoSCL*)malloc(sizeof(NodoSCL));
      node->value = curr_value;
      node->count = 1;
      node->next = NULL;
      aggiungiNodo(root,node);
    }    
  }
  
  return root;
}
