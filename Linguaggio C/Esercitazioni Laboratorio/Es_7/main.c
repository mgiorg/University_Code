/**
 * Esercitazione SCL
*/
#include "funzioni.c"

int main() {
	TipoSCL scl = (TipoSCL)malloc(sizeof(TipoNodoSCL));
	TipoSCL temp = scl;
	TipoSCL nodo;

	for(int i = 0; i < 5; ++i) {
		temp-> info = i+1;
		temp->next = (TipoSCL)malloc(sizeof(TipoNodoSCL));
		temp = temp-> next;
	}
	
	printf("Lunghezza SCL: %d\n", scl_len(scl));
	printf("Somma SCL: %f\n", scl_sum(scl));
	printf("Media SCL: %f\n", scl_media(scl));

	scl_print(scl);
	scl_duplicate(scl, 3);
	scl_print(scl);

	
	scl_append(scl, nodo);
	printf("Lunghezza SCL: %d\n", scl_len(scl));
	scl_print(scl);

	scl_free(scl);
	printf("Fine della free\n");

	return 0;
}