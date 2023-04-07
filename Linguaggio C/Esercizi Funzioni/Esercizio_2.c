/**
 * 	Scrivere una funzione dist2d(x1, x2, y1, y2) che calcoli e restituisca la distanza tra i due punti
	passati come parametri (numeri in virgola mobile)
 */
#include <math.h>

#include <stdio.h>


float distanza(int x1, int x2, int y1, int y2);

int main()
{
	int x1, x2, y1, y2;
	printf("Inserire due punti lungo l'asse X:\n");
	scanf("\t%d", &x1);
	scanf("\n%d", &x2);

	printf("Inserire due punti lungo l'asse Y:\n");
	scanf("\t%d", &y1);
	scanf("\n%d", &y2);

	float dist = distanza(x1, x2, y1, y2);
	printf("La distanza tra i due punti è %f", dist);

	return 0;
}

float distanza(int x1, int x2, int y1, int y2)
{
	//distanza tra due punti
	int x = x2 - x1;
	int y = y2 - y1;

	float i = sqrt(x*x + y*y);

	return i;
}
