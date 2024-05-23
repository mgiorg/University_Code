#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TipoInfoMat;

typedef struct
{
	int rows;
	int cols;
	TipoInfoMat **row_ptrs;
} Mat;

Mat *allocMatrix(int rows, int cols)
{
	Mat *m = (Mat *)malloc(sizeof(Mat));
	m->rows = rows;
	m->cols = cols;

	m->row_ptrs = (int **)malloc(sizeof(int *) * rows);
	for (int r = 0; r < rows; r++)
		m->row_ptrs[r] = (int *)malloc(sizeof(int) * cols);

	return m;
}

void freeMatrix(Mat *src)
{
	if (src == NULL)
		return;
	int rows = src->rows;
	//  int cols = src->cols;
	for (int r = 0; r < rows; ++r)
		free(src->row_ptrs[r]);

	free(src);
}

Mat *randomMat(int rows, int cols, int max)
{
	Mat *m = allocMatrix(rows, cols);

	max++;
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			m->row_ptrs[r][c] = rand() % max;

	return m;
}

Mat *uniformMat(int rows, int cols, int val)
{
	Mat *m = allocMatrix(rows, cols);

	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			m->row_ptrs[r][c] = val;

	return m;
}

void printMatrix(Mat *src)
{
	if (src == NULL)
	{
		printf("NULL\n");
		return;
	}
	int rows = src->rows;
	int cols = src->cols;
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
		{
			printf("%d\t", src->row_ptrs[r][c]);
		}
		printf("\n");
	}
	fflush(stdout);
}

typedef struct
{
	int row;
	int col;
	int len;
	char dir;
} Nave;

Nave *creaNave(int row, int col, int len, char dir)
{

	if (dir != 'U' && dir != 'D' && dir != 'L' && dir != 'R')
	{
		dir = 'U';
	}
	Nave *nv = (Nave *)malloc(sizeof(Nave));
	nv->row = row;
	nv->col = col;
	nv->len = len;
	nv->dir = dir;
	return nv;
}

bool compareMatrix(Mat *m1, Mat *m2)
{
	if (m1->rows != m2->rows)
	{
		return false;
	}
	if (m1->cols != m2->cols)
	{
		return false;
	}

	for (int r = 0; r < m1->rows; r++)
	{
		for (int c = 0; c < m1->cols; c++)
		{
			if (m1->row_ptrs[r][c] != m2->row_ptrs[r][c])
			{
				return false;
			}
		}
	}
	return true;
}

void printNv(Nave *nv)
{
	printf("Nave: \n");
	printf("riga = %d\n", nv->row);
	printf("colonna = %d\n", nv->col);
	printf("lunghezza = %d\n", nv->len);
	printf("direzione = %c\n", nv->dir);
}