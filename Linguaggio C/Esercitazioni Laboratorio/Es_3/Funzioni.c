

int* allocaInt() {
	return (int*)malloc(sizeof(int));
}

void printInt(int* i1, int* i2) {
	printf("%d\n", *i1 + *i2);
}

bool soluzioneEquazione(int a, int b, int c, double *x1, double *x2) {
	int discriminante = (b*b) - (4*a*c);
	double rad = sqrt(discriminante);
	
	if(rad > 0) {
		//! Soluzioni reali e distinte
		*x1 = (double) (-b + rad)/(2*a);
		*x2 = (double) (-b - rad)/(2 * a);
		return true;
	}
	else if(rad == 0) {
		//! Soluzioni reali e coincidenti
		*x1 = (double) -b/(2*a);
		*x2 = *x1;
		return true;
	}
	else {
		//! Soluzioni COMPLESSE e CONIUGATE
		return false;
	}
}
double *soluzioneEquazionePtr(int a, int b, int c) {
	int discriminante = (b * b) - (4 * a * c);
	double rad = sqrt(discriminante);
	
	double* p = (double* )malloc(2 * sizeof(double));
	if (rad > 0)
	{
		//! Soluzioni reali e distinte
		*p = (double)(-b + rad) / (2 * a);
		*(p+1) = (double)(-b - rad) / (2 * a);
	}
	else if (rad == 0)
	{
		//! Soluzioni reali e coincidenti
		*p = (double)-b / (2 * a);
		*(p+1) = *p;
	}
	else //! Soluzioni COMPLESSE e CONIUGATE
		free(p);
	printf("Risultato x1: %lf\nRisultato x2: %lf\n", *p, *(p + 1));
	return p;
}