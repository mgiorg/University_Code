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
	int** campo_minato;
	int** marcata;
} CampoMinato;

CampoMinato* initBoard(int n, int mine) {
	printf("Init Board\n");
	CampoMinato* campo;
	campo-> n = n;
	campo-> mine = mine;
	campo-> campo_minato = (int** )malloc(n*sizeof(int*));
	campo-> marcata = (int** )malloc(n*sizeof(int*));
	
	for(int i = 0; i < campo-> n; ++i) {
		campo->campo_minato[i] = (int* )malloc(n * sizeof(int));
		campo->marcata[i] = (int* )malloc(n * sizeof(int));
		for(int j = 0; j < campo-> n; ++j) {
			campo->campo_minato[i][j] = false;
			campo->marcata[i][j] = false;
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
		for (int i = 0; i < campo->n; ++i)
		{
			for (int j = 0; j < campo->n; ++j)
			{
				if (campo->campo_minato[i][j] == true)
					printf("X ");
				else if(campo->marcata[i][j] == true) 
					printf("* ");
				else printf(". ");
			}
			printf("\n");
		}
	}
}

bool is_bomb(CampoMinato *campo, int row, int col) {
	if(campo-> campo_minato[row][col] == 1) {
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
	if (row < 0 || col < 0 || row >= campo-> n ||col >= campo->n) 
		return false;
	if(is_bomb(campo, row, col))
		return false;
	else return 1;
}

int cercaVuoti(CampoMinato *campo, int row, int col) {
	
	if (completato(campo) == true)
	{
		return true;
	}
	if(percorribile(campo, row, col) == false) {
		return false;
	}
	else {
		if (campo->marcata[row][col] == 0)
		{
			
			campo-> marcata[row][col] = 1;
			return  cercaVuoti(campo, row - 1, col) ||
					cercaVuoti(campo, row + 1, col) ||
					cercaVuoti(campo, row, col - 1) ||
					cercaVuoti(campo, row, col + 1);
		}
	}
	return false;
}