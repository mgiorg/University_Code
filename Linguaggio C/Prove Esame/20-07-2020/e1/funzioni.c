#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Questa è la struttura Mat
typedef struct
{
	int rows;
	int cols;
	int **mat;
} Mat;

void mat_free(Mat *m)
{
	free(*m->mat);
	free(m->mat);
	free(m);
}
void mat_print(const Mat *m)
{

	if (m == NULL)
	{
		printf("NULL");
		return;
	}

	for (int r = 0; r < m->rows; ++r)
	{
		for (int c = 0; c < m->cols; ++c)
		{
			printf("%d, ", m->mat[r][c]);
		}
		printf("\n");
	}
}
void vec_print(int *vec, int size)
{

	if (vec == NULL)
	{
		printf("NULL\n");
		return;
	}

	for (int r = 0; r < size; ++r)
	{

		printf("%d, ", vec[r]);
	}
}
Mat *mat_alloc(int rows, int cols)
{

	Mat *m = (Mat *)malloc(sizeof(Mat));

	m->cols = cols;
	m->rows = rows;
	m->mat = (int **)malloc(sizeof(int *) * rows);

	int *row_p = (int *)malloc(sizeof(int) * rows * cols);
	for (int i = 0; i < rows; ++i)
	{
		m->mat[i] = row_p;
		row_p += cols;
	}

	return m;
}			// Dealloca una matrice
