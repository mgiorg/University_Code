#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "record_annidati.h"

int main() {
	/*struct persona p1;

	p1.nome = "Massimo";
	p1.cognome = "Giordano";
	p1.giorno = 11;
	p1.mese = 9;
	p1.anno = 2003;

	struct persona p2 = {"Flavia", "Feliciani", 13, 3, 2004};

	struct persona p3 = {
		.nome = "Mario",
		.cognome = "Rossi",
		.giorno = 12,
		.mese = 5,
		.anno = 2004
	};

	struct persona p4 = p3;
	struct persona* puntatore;

	printf("%s %s %d/%d/%d\n", p1.nome, p1.cognome, p1.giorno, p1.mese, p1.anno);
	printf("%s %s %d/%d/%d\n", p2.nome, p2.cognome, p2.giorno, p2.mese, p2.anno);
	printf("%s %s %d/%d/%d\n", p3.nome, p3.cognome, p3.giorno, p3.mese, p3.anno);
	printf("%s %s %d/%d/%d\n\n", p4.nome, p4.cognome, p4.giorno, p4.mese, p4.anno);

	puntatore = &p1;
	inizializza(puntatore);
	printf("%s %s %d/%d/%d\n", p1.nome, p1.cognome, p1.giorno, p1.mese, p1.anno);*/


	/*struct persona* p = (struct persona*)malloc(sizeof(struct persona));
	struct persona* tmp = p;

	for(int i = 0; i < 5; ++i) {
		tmp-> nome = "Massimo";
		tmp-> cognome = "Giordano";
		tmp-> giorno = 3*i;
		tmp-> mese = 30*i;
		tmp-> anno = 300*i;

		printf("%s %s %d/%d/%d\n", tmp->nome, tmp->cognome, tmp->giorno, tmp->mese, tmp->anno);
		printf("indirizzo di p: %p\n", tmp);

		tmp = tmp-> next;
		tmp = (struct persona*)malloc(sizeof(struct persona));
	}
	free(tmp);
	free(p);*/

	/*struct punto punto_uno = {5, 8, 10};

	struct punto_colorato p_verde = {punto_uno, "Verde"};
	struct punto_colorato* p = &p_verde;
	printf("%hd\n", p->punto.x);*/
	
	
	/*union Unione {
		uint8_t i;
		char c;
		int8_t carattere;
	};
	union Unione unione;
	unione.i = 0;
	printf("size: %lu\n", sizeof(unione));

	unione.c = 'c';
	printf("size: %lu\n", sizeof(unione));
	
	unione.carattere = 1000;
	printf("size: %lu\n", sizeof(unione));

	I TIPI DI  DATO UNION VENGONO TRATTATI ALLO STESSO MODO DEI RECORD
	PER QUANTO RIGUARDA LA GESTIONE DELLE VARIABILI, LA DICHIARAZIONE E L'USO DEI PUNTATORI

	LA MEMORIA VIENE GESTITA DIVERSAMENTE, IN BASE AL PESO DELLA VARIABILE PIù GRANDE
	=> IL DATO SIGNIFICATIVO DEELL'UNION è SOLO L'ULTIMO A CUI è STATO ASSEGNATO UN VALORE.
	=> RICHIEDE UNA MAGGIORE QUANTITà DI MEMORIA*/

	/*typedef enum {
		ALTO,
		BASSO,
		DESTRA,
		SINISTRA
	}Direzione;

	Direzione dir;
	dir = ALTO;

	if(dir == BASSO) printf("BASSO\n");
	else if(dir == ALTO) printf("ALTO\n");

	PUò ESSERE USATA COME QUALUNQUE ALTRA VARIABILE*/
}