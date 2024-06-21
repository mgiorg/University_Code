#include <stdio.h>
#include <stdlib.h>
typedef int TipoInfoSCL;

struct ElemSCL{
    TipoInfoSCL info;
    struct ElemSCL* next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

void doSCL(TipoSCL *l, TipoInfoSCL e){
    TipoSCL temp = *l;
    *l = (TipoNodoSCL*) malloc(sizeof(TipoNodoSCL));
    (*l)->info = e;
    if (temp!=NULL && temp->next!=NULL)
        (*l)->next = temp->next;
    else
        (*l)->next = temp;
}

int main() {
	TipoSCL l1 = NULL;
	doSCL(&l1,9);
	doSCL(&l1,5);
	doSCL(&l1,3);
	doSCL(&l1,1);

	for (TipoSCL p=l1; p!=NULL; p=p->next)
		printf("%d ", p->info);
	printf("\n");

	return 0;
}
