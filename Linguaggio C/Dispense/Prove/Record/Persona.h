#ifndef PERSONA_H
#define PERSONA_H

struct persona {
	char* nome;
	char* cognome;
	short int giorno, mese, anno;

	struct persona* next;
};

void inizializza(struct persona* p);
struct persona* nuovaPersona(char* nome, char* cognome, short giorno, short mese, short anno);

#endif