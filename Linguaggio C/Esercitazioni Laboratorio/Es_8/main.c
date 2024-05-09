#include "insf_scl.c"

//-------IMPLEMENTAZIONE FUNZIONI-------
Insieme init(int* arr, int n);
void print(Insieme s);
Insieme copy(Insieme s);
int size(Insieme s);
bool subset(Insieme a, Insieme b);
Insieme intersection(Insieme a, Insieme b);
Insieme unione(Insieme a, Insieme b);


int main() {
	int arr[] = {0, 1, 2, 3, 4};
	
	Insieme ins = init(arr, 5);
	print(ins);
	Insieme copia = copy(ins);
	print(copia);
	printf("Size: %d\n", size(ins));

	if(subset(copia, ins)) printf("Completamente contenuto\n");

	while (ins != NULL)
	{
		Insieme nodoDaRimuovere = ins;
		ins = ins->next;
		free(nodoDaRimuovere);
	}

	while (copia != NULL)
	{
		Insieme nodoDaRimuovere = copia;
		copia = copia->next;
		free(nodoDaRimuovere);
	}

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
		temp++;
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