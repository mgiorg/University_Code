#include "funzioni.c"

int main() {

	float array[5] = {1, 2, 3, 4, 5}; // == 120;
	printf("Il prodotto dell'array è: %f\n", product(array, 5));
	vec_integral(array, 5);
	printf("[ ");
	for(int i = 0; i < 5; ++i) {
		printf("%f ", array[i]);
	}
	printf("]\n");

	char* s = "Mamma ho perso l'aereo";
	printf("La lunghezza della stringa 'Mamma ho perso l'aereo è: %d\n", lenght(s));

	char c = 'z';
	printf("%d\n", (int)c); //97-122
	printf("Lower case: %d\n", is_any_lowercase(s));

	return 0;
}