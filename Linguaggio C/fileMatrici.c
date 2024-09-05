#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.c"
int sommaRiga(Mat* m, int* index) {
	int maxSomma = -999;
	int somma = 0;
	for(int i = 0; i < m-> rows; ++i) {
		for(int j = 0; j < m-> cols; ++j) {
			somma+= m-> mat[i][j];
		}
		if(somma > maxSomma) {
			maxSomma = somma;
			*index = i;
		}
		somma = 0;
	}
	return maxSomma;
}
int sommaCol(Mat* m, int* index) {
	int maxSomma = -999;
	int somma = 0;
	for(int i = 0; i < m-> cols; ++i) {
		for(int j = 0; j < m-> rows; ++j) {
			somma+= m-> mat[j][i];
		}
		if(somma > maxSomma) {
			maxSomma = somma;
			*index = i;
		}
		somma = 0;
	}
	return maxSomma;
}
int* copiaRiga(Mat* m, int i) {
	int* row = (int*) malloc(m-> cols * sizeof(int));
	for(int j = 0; j < m-> cols; ++j) {
		row[j] = m-> mat[i][j];
	} return row;
}
int* copiaCol(Mat* m, int j) {
	int* col = (int*) malloc(m-> rows * sizeof(int));
	for(int i = 0; i < m-> rows; ++i) {
		col[i] = m-> mat[i][j];
	}
}

Mat* funzione(Mat* m) {
	int index_row, index_col;
	int max_somma_row = sommaRiga(m, &index_row);
	int max_somma_col = sommaCol (m, &index_col);

	Mat* tmp = mat_alloc(m-> rows+1, m-> cols);
	bool flag = false;
	for(int i = 0, i_t = 0; i < m-> rows, i_t < tmp-> rows; i++, i_t++) {
		for(int j = 0; j < tmp-> cols; j++) {
			tmp-> mat[i_t][j] = m-> mat[i][j];
		}
		if(i == index_row && flag == false) {
			i--;
			flag = true;
		}
	}
	mat_print(tmp);

	Mat* res = mat_alloc(tmp-> rows, tmp-> cols+1);
	flag = false;
	for(int i = 0, i_t = 0; i < tmp-> cols, i_t < res-> cols; i++, i_t++) {
		for(int j = 0; j < res-> rows; j++) {
			res-> mat[j][i_t] = tmp-> mat[j][i];
		}
		if(i == index_col && flag == false) {
			i--;
			flag = true;
		}
	}
	printf("\n\n");
	mat_print(res);
	return NULL;
}

int main() {
	Mat* m = mat_alloc(3, 4);
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 4; ++j) {
			m-> mat[i][j] = j-i;
		}
	}
	mat_print(m);
	printf("\n\n");


	funzione(m);

	mat_free(m);

	return 0;
}