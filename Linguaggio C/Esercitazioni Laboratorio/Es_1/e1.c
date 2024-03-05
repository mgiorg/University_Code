/**
 * e1.c
 * ax+b = 0
*/

#include <stdio.h>

int main()
{
	float a, b;
	printf("Inserire valore di a: ");
	scanf("%f", &a);

	printf("Inserire valore di b: ");
	scanf("%f", &b);

	if(a != 0)
	{
		float x = -b/a;
		printf("La soluzione dell'equazione è x = %.2f\n", x);
	}
	else
	{
		printf("Impossibile determinare una x");
	}
	return 0;
}