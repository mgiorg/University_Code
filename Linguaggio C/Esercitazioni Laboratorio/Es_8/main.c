#include "insf_scl.c"

//-------IMPLEMENTAZIONE FUNZIONI-------
Insieme init(int* arr, int n);
void print(Insieme s);
Insieme copy(Insieme s);
int size(Insieme s);
bool subset(Insieme a, Insieme b);
bool equal(Insieme a, Insieme b);
Insieme intersection(Insieme a, Insieme b);
Insieme unione(Insieme a, Insieme b);
void insieme_free(Insieme a);


int main() {
	int arr[] = {0, 1, 2, 3, 4};
	int arr2[] = {4, 6, 7, 8, 9};
	
	Insieme ins = init(arr, 5);
	Insieme ins2 = init(arr2, 5);

	Insieme risultato = intersection(ins, ins2);

	if(risultato == NULL) printf("Diversi\n");
	else {
		print(risultato);
	}

	insieme_free(ins);
	insieme_free(ins2);
	//insieme_free(risultato);

	return 0;
}

Insieme init(int* arr, int n) {
	//Inizializza una struttura insieme contenente gli elementi
	//dell'array arr di dimensione n
	Insieme ins = (Insieme)malloc(sizeof(TipoNodo));
	ins-> info = arr[0];
	Insieme temp = ins;
	for(int i = 1; i < n; ++i) {
		temp->next = (Insieme)malloc(sizeof(TipoNodo));
		temp = temp-> next;
		temp-> info = arr[i];
	}
	return ins;
}

void print(Insieme s) {
	Insieme temp = s;
	printf("\n[ ");
	while(temp != NULL) {
		printf("%d ", temp->info);
		temp = temp->next;
	}
	printf("]\n");
}

Insieme copy(Insieme s) {
	if(s != NULL) {
		Insieme copia = (Insieme)malloc(sizeof(TipoNodo));
		copia->info = s->info;
		Insieme temp_copia = copia;
		Insieme temp_s = s;
		while (temp_s-> next != NULL) {
			temp_copia->next = (Insieme)malloc(sizeof(TipoNodo));
			temp_copia = temp_copia-> next;
			temp_s = temp_s->next;
			temp_copia->info = temp_s->info;
		}
		return copia;
	}
	
	return NULL;
}

int size(Insieme s) {
	int c = 0;
	Insieme temp = s;
	while(temp != NULL) {
		c++;
		temp = temp-> next;
	}
	return c;
}

bool subset(Insieme a, Insieme b) {
	Insieme temp = a;
	while(temp != NULL) {
		T valore_corrente = temp-> info;
		if(!membro(b, valore_corrente)) {
			return false;
		}
		temp = temp-> next;
	}

	return true;
}

bool equal(Insieme a, Insieme b) {
	Insieme t_a = a;
	Insieme t_b = b;
	while(t_b != NULL || t_a != NULL) {
		if(!membro(a, t_b-> info) || !membro(b, t_a-> info)) return false;
		t_a = t_a-> next;
		t_b = t_b-> next;
	}
	return true;
}

Insieme intersection(Insieme a, Insieme b) {
	Insieme t_a = a;
	Insieme intersezione;
	Insieme t_i = intersezione;
	while(t_a != NULL) {
		if(membro(b, t_a-> info)) {
			t_i = (Insieme)malloc(sizeof(TipoNodo));
			t_i-> info = t_a-> info;
			t_i = t_i->next;
		}
		t_a = t_a-> next;
	}
	return intersezione;
}

void insieme_free(Insieme ins) {
	while (ins != NULL)
	{
		Insieme nodoDaRimuovere = ins;
		ins = ins->next;
		free(nodoDaRimuovere);
	}
}