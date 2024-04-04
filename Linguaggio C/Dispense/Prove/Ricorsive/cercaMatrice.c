/**
 * * Cerca Matrice
 * ----------------------------------------------------------------
 * * Gioco in cui si ha una matrice di R x C zone, ognuna può essere calpestabile o meno.
 * * Far trovare il percorso al programma in maniera ricorsiva (vale anche in diagonale).
*/
#include "cercaMatrice.h"

int terra(int **m, int r, int c)
{
	return (r >= 0) && (r < R) && (c >= 0) && (c < C) && m[r][c];
}

void initPalude(int **m, double prob)
{
	srand(time(NULL));
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; ++c)
		{
			m[r][c] = rand() / (double)RAND_MAX < prob;
		}
	}
}

void stampaPalude(int **m)
{
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; ++c)
		{
			printf("%d\t", m[r][c]);
		}
		printf("\n");
	}
}

int cercaMatrice(int **m, int r, int c, int camm[])
{
	if (!terra(m, r, c))
		return 0;
	else
	{
		camm[c] = r;
		if (c == C - 1)
			return 1;
		else
			return cercaMatrice(m, r - 1, c + 1, camm) ||
				   cercaMatrice(m, r, c + 1, camm) ||
				   cercaMatrice(m, r + 1, c + 1, camm);
	}
}