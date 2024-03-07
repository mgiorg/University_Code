#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem{
	int i ;
	int j;
	int x;

	struct elem* next;
}elem;

struct mat_head{
	int r;
	int c;

	struct elem* head;
};

struct elem* crea_elem(){
	struct elem* e=(struct elem*)malloc(sizeof(struct elem));
	e->next=NULL;
	return e;
};

struct mat_head* crea_mat(int r, int c){
	struct mat_head *h = (struct mat_head*)malloc(sizeof(struct mat_head));
	h->c = c;
	h->r = r;
	h->head = crea_elem();

	struct elem* temp=h->head;

	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			temp->i=i;
			temp->j=j;
			temp->x=i;
			if(i <= r){
				struct elem* e=crea_elem();
				temp->next=e;
				temp=temp->next;
			}
		}
	}
	return h;
}
long int sizetot(struct mat_head* h){
	struct elem* temp=h->head;
	long int size=0;
	while(temp->next!=NULL){
		size+=sizeof(*temp);
		temp=temp->next;
	}
	return size;
}

int main(){
	struct mat_head *m=crea_mat(2,3);
	struct elem *temp=m->head;
	while(temp->next!=NULL){
		printf("%d\n",temp->x);
		temp=temp->next;
	}
	int elem_num=(m->r)*(m->c);
	printf("size=%lu\n",sizetot(m));
	return 0;
}