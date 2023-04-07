/**
 * main.c
 */
#include <stdio.h>

/**
 * -> Specifiche di conversione(%X):
 * 		%d -> int
		%u -> unsigned int
		%x -> unsigned int in esadecimale
		%hd -> short int
		%ld -> long int
		%lu -> unsigned long int
		%f -> Stampa valori a virgola mobile (formato decimale) (.p = numero di cifre dopo la virgola; def = 6)
		%e -> Valori con la virgola (notazione scientifica; mantissa < 10)  (.p = numero di cifre della mantissa; def = 6)
		%g -> Stampa in formato decimale o esponenziale, in base alla dimensione (.p = numero di cifre significative da stampare)
		%lf -> double
		%Lf -> long double
 *
 * -> Campo di ampiezza MINIMA(%mX _ %-mX):
 * 		ex. %5d = stampa ALMENO 5 caratteri (se non scrivo 5 caratteri mi aggiunge spazi prima del mio intero)
 * 		ex. printf("__%5d__", 50) = __   50__(3 spazi prima del numero)
 *   	se scrivo %-5d gli spazi li aggiunge DOPO l'intero se non soddisfo il numero minimo di caratteri
 *   	
 * -> Campo di PRECISIONE(%.pX; il significato dipende dal tipo della specifica):
 * 		ex. %d -> p: Numero minimo di cifre da spampare (eventuali zeri aggiuntivi all'inizio del numero)
 *
 * -> Azioni durante la stampa:
 * 		\n = New Line (va a capo)
 * 		\t = Tab
 * 		\b = Backspace (posiziona il cursore indietro di una posizione)
 * 		\a = Alert (emette un suono)
 *   	.
 *   	.
 *   	\" = stampa il carattere "
 *   	\\ = stampa il carattere \
 * 
 */

int main()
{
	printf("\\%d");
	return 0;
}