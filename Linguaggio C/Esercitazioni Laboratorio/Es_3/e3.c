#include <stdio.h>
#include <stdlib.h>

int main() {
	void* unico = malloc(sizeof(float) + sizeof(char));
	float* reale = (float*) (unico);
	char* c = (char*) (unico+4);

	printf("Inserire numero gradi: ");
	scanf("%f", reale);
	printf("Inserire tipo di gradi: ");
	scanf("%s", c);

	if(*c == 'C') { //Celsius
		printf("K= %.2f\n", (*reale)+273.15);
		printf("F= %.2f\n", (*reale) *9/5 +32);
	}
	if(*c == 'K') { //Celsius
		printf("C= %.2f\n", (*reale)-273.15);
		printf("F= %.2f\n", ((*reale)-273.15) *9/5 +32);
	}
	if(*c == 'F') { //Celsius
		printf("C= %.2f\n", ((*reale)-32)*5/9);
		printf("K= %.2f\n", ((*reale)-32)*5/9 + 273.15);
	}

	return 0;
}