#include <stdio.h>
#include <stdlib.h>
#include "func.c"

int main()
{
	int row = 0, col = 0;
	CampoMinato* campo = initBoard(15, 60);
	generateMines(campo);
	print_board(campo, 'C');

	while(1) {

		printf("\nInserire riga e colonna nel formato numero-numero: ");
		scanf("%d-%d", &row, &col);
		if(row >= campo-> n || col >= campo-> n) {
			printf("Errore, inserire ancora le coordinate.\n");
		}

		else {
			if (is_bomb(campo, row, col))
			{
				printf("Hai trovato una bomba\nGame Over!\n");
				break;
			}
			if (cercaVuoti(campo, row, col))
			{
				printf("BRAVO, HAI COMPLETATO IL GIOCO!!!\n");
				print_board(campo, 'C');
				break;
			}
			print_board(campo, 'M');
			campo-> risultato[row][col] = contaBombe(campo, row, col);
			print_board(campo, 'R');
		}
	}
	
	
	

	return 0;
}
