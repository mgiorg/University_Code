#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sort.c"

#define MINE 10
#define N 5

typedef struct
{
	int n, mine;
	int* array;
	int** campo_minato;
	int** marcata;
	int** risultato;
} CampoMinato;

CampoMinato* initBoard(int n, int mine) {
	printf("Init Board\n");
	CampoMinato* campo;
	campo-> n = n;
	campo-> mine = mine;
	campo-> array = (int* )calloc(n*n, sizeof(int));
	campo-> campo_minato = (int** )malloc(n*sizeof(int*));
	campo-> marcata = (int** )malloc(n*sizeof(int*));
	campo-> risultato = (int **)malloc(n * sizeof(int *));

	for(int i = 0; i < campo-> n; ++i) {
		campo->campo_minato[i] = (int* )malloc(n * sizeof(int));
		campo->marcata[i] = (int* )malloc(n * sizeof(int));
		campo->risultato[i] = (int *)malloc(n * sizeof(int));
		for(int j = 0; j < campo-> n; ++j) {
			campo->campo_minato[i][j] = false;
			campo->marcata[i][j] = false;
			campo-> risultato[i][j] = -1;
		}
	}
	return campo;
}

void generateMines(CampoMinato* campo) {
	for(int j = 0; j < campo-> mine; ++j) {
		int row = rand() % campo-> n;
		int col = rand() % campo->n;
		if (campo->campo_minato[row][col] != true) {
			campo->campo_minato[row][col] = true;
		}
		else j--;
	}
}

void print_board(CampoMinato *campo, char c)
{
	if(c == 'C') {
		printf("-----Campo_Minato-----\n");
		for (int i = 0; i < campo->n; ++i)
		{
			for (int j = 0; j < campo->n; ++j)
			{
				if (campo->campo_minato[i][j] == true) printf("X ");
				else printf("* ");
			}
			printf("\n");
		}
	}
	if (c == 'M') {
		printf("-----Marcata-----\n");
		for (int i = 0; i <= campo->n; ++i)
		{
			for (int j = 0; j <= campo->n; ++j)
			{
				if(i == 0 && j == 0) printf(" \t");
				else if(i == 0) printf("%d\t", j-1);
				else if(j == 0) printf("%d\t", i-1);
				else {
					if (campo->campo_minato[i-1][j-1] == true)
						printf("X\t");
					else if(campo->marcata[i-1][j-1] == true) 
						printf("*\t");
					else printf(".\t");
				}
			}
			printf("\n\n");
		}
	}
	if (c == 'R') {
		printf("-----Risultato-----\n");
		for (int i = 0; i < campo->n; ++i) {
			for (int j = 0; j < campo->n; ++j) {
				if (campo->risultato[i][j] == -1)
					printf("* ");
				else if (campo->risultato[i][j] == false)
					printf("  ");
				else
					printf("%d ", campo->risultato[i][j]);
			}
			printf("\n");
		}
	}
}

bool is_bomb(CampoMinato *campo, int row, int col) {
	if (row >= 0 && col >= 0 && row < campo->n && col < campo->n && campo->campo_minato[row][col] == 1)
	{
		return true;
	}
	else return false;
}

bool completato(CampoMinato *campo) {
	int contatore = 0;
	for(int i = 0; i < campo-> n; ++i) {
		for(int j = 0; j < campo-> n; ++j) {
			if(campo-> marcata[i][j] == 0) 
				contatore++;
		}
	}

	if(contatore == campo-> mine) {
		return true;
	}
	else return false;
}

int percorribile(CampoMinato *campo, int row, int col) {
	if (row >= 0 && col >= 0 && row < campo-> n &&col < campo->n && is_bomb(campo, row, col) == false) 
		return true;
	else return false;
}

int cercaVuoti(CampoMinato *campo, int row, int col) {
	// * Deve sbloccare completamente solo le caselle che non
	// * hanno bombe intorno. 
	
	if (completato(campo) == true)
	{
		return true;
	}
	else if(percorribile(campo, row, col) == false) {
		return false;
	}
	else {
		if (campo->marcata[row][col] == false)
		{
			campo->marcata[row][col] = true;
			if ((is_bomb(campo, row - 1, col - 1) || is_bomb(campo, row - 1, col) || is_bomb(campo, row - 1, col + 1) ||
				is_bomb(campo, row, col - 1) 	 || is_bomb(campo, row, col + 1) ||
				is_bomb(campo, row + 1, col - 1) || is_bomb(campo, row + 1, col) || is_bomb(campo, row + 1, col + 1)) == false)
					return cercaVuoti(campo, row-1, col-1) ||
						cercaVuoti(campo, row, col-1) ||
						cercaVuoti(campo, row+1, col-1) ||
						cercaVuoti(campo, row-1, col) ||
						cercaVuoti(campo, row+1, col) ||
						cercaVuoti(campo, row-1, col+1) ||
						cercaVuoti(campo, row, col+1) ||
						cercaVuoti(campo, row+1, col+1);
					
		}
	
	return false;
	}
}

bool cellaCorretta(CampoMinato* campo, int row, int col) {
	if (row >= 0 && col >= 0 && row < campo->n && col < campo->n)
		return true;
	else return false;
}

int contaBombe(CampoMinato* campo, int row, int col) {

	if (is_bomb(campo, row, col) && campo-> marcata[row][col] == false) 
		return 1;
	else{
		if(campo-> risultato[row][col] == -1 && campo-> marcata[row][col] == true) {
			campo->risultato[row][col] = contaBombe(campo, row + 1, col - 1) +
											contaBombe(campo, row, col - 1) +
											contaBombe(campo, row - 1, col - 1) +
											contaBombe(campo, row + 1, col) +
											contaBombe(campo, row - 1, col) +
											contaBombe(campo, row + 1, col + 1) +
											contaBombe(campo, row, col + 1) +
											contaBombe(campo, row - 1, col + 1);
		}
		return 0;
	}
	
}