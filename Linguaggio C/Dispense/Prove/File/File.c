#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* file = fopen("/Users/massimogiordano/Desktop/Programmazione/University_Code/Linguaggio C/Dispense/Prove/File/MioFile.txt", "w+");

	if(file == NULL) {
		printf("Errore nell'apertura del file");
		exit(1);
	}
	for(int i = 0; i < 3; ++i) {
		fprintf(file, "Questa è la riga numero %d\n", i);
	}

	int ok = fclose(file);
	if(ok != 0) {
		printf("Errore nella chiusura del file");
		exit(1);
	}

	return 0;
}