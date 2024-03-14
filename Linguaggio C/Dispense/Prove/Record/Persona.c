#include "Persona.h"
#include <stdlib.h>

void inizializza(struct persona* p) {
	p-> nome = ".";
	p-> cognome = ".";
	p-> giorno = 0;
	p-> mese = 0;
	p-> anno = 0;
}

struct persona* nuovaPersona(char* nome, char* cognome, short giorno, short mese, short anno) {
	struct persona* p = (struct persona*)malloc(sizeof(struct persona));
	p-> nome = nome;
	p-> cognome = cognome;
	p-> giorno = giorno;
	p-> mese = mese;
	p-> anno = anno;

	return p;
}
