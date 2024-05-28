#include "funzioni.c"

int size(TipoSCL list) {
  if(list == NULL) return 0;
  else return 1 + size(list-> next);
}

void somma(TipoSCL lis, int i, int j, int* somma_tot) {
  if(lis == NULL) return;
  else {
    if(i == 0){
    	*somma_tot += lis-> info;
    }
    if(j == 0) {
    	*somma_tot += lis-> info;
    }
      
    somma(lis-> next, i-1, j-1, somma_tot);
  }
}

int sommaElementi(TipoSCL lis, int i, int j){
  	int somma_tot = 0;
 	if(i >= size(lis) || j >= size(lis)) return -1;
  	else{somma(lis, i, j, &somma_tot); return somma_tot;}

	return -1;
}

void sommaDispari(TipoSCL lis, TipoSCL ris, int pos, int* somma) {
  	if(lis == NULL) return;
	if(pos%2 == 0) {
      	ris-> info = lis-> info;
    	sommaDispari(lis-> next, ris-> next, pos+1, somma);
    }
  	else {
    	*somma+= lis-> info;
      	ris-> info = *somma;
      	sommaDispari(lis-> next, ris-> next, pos+1, somma);
    }
}

void sommatoriaDispari(TipoSCL lis, TipoSCL ris){
	int somma = 0;
  	sommaDispari(lis, ris, 0, &somma);
}

int main() {


	return 0;
}