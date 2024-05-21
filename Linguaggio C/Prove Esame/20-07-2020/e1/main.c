#include "funzioni.c"

int *controlla_colonne(Mat *m, double w, double v)
{
	double media = 0;
	int *risultato = (int *)calloc(m->rows, sizeof(int));
	for (int i = 0; i < m->cols; ++i)
	{
		for (int j = 0; j < m->rows; ++j)
		{
			media += m->mat[j][i];
		}
		media = (double)media / m->rows;
		if (media >= w && media <= v)
		{
			risultato[i] = 1;
		}
		else
		{
			risultato[i] = 0;
		}
		media = 0;
	}
	return risultato;
}

int main() {
	Mat* matrice = mat_alloc(3, 3);
	mat_print(matrice);

	int* risultato = controlla_colonne(matrice, 1, 2);

	return 0;
}