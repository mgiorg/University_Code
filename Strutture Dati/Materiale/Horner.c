#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double pol(double[], int, double);
double pol_bis(double[], int, double);

/* a[i] contiene coeff. del termine di grado i */

double pol(double a[], int grado, double x) { /* array di grado+1 componenti */
	if(grado == 0) return a[0];
	return a[grado] + x*pol(a, grado-1, x);
}


double pol_bis(double a[], int grado, double x) { /* array di grado+1 componenti */
	double sum = a[0];
	for(int i = 1; i <= grado ; i++)
		sum = sum*x + a[i];
	return sum;
}

int main(int argc, char* argv[]) {
	int grado = argc-2;
	double* polin = malloc((grado+1)*sizeof(double));
	for(int i = grado; i >= 0; i--) 
		polin[i] = strtod(argv[i+1], NULL);
	double x;
	while(1) {
		printf("ascissa = ");
		scanf("%lf", &x);
		printf("P(%g) = %g; iterativo = %g\n", x, pol(polin, grado, x), pol_bis(polin, grado, x));
	}
	return 0;
}
	
