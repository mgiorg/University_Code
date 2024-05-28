#include "funzioni.c"

int contaMax(TipoAlbero a) {
	//Inizialmente max = 0;
	if(a == NULL) 
		return -9999;

	else if(sinistro(a) == NULL && destro(a) == NULL && a != NULL) return radice(a);  
	else {
		if(sinistro(a) != NULL || destro(a) != NULL) {
			int maxSx = radice(a) + contaMax(sinistro(a));
			int maxDx = radice(a) + contaMax(destro(a));
          
			if(maxDx > maxSx) return maxDx;
			else return maxSx;
		}
	}
	return -999;
}

TipoAlbero figlio_lontano(TipoAlbero a) {
	if(estVuoto(a)) return albBinVuoto();
	else if(sinistro(a) == NULL && destro(a) == NULL) return creaAlbBin(radice(a), NULL, NULL);
	else {
		return creaAlbBin(contaMax(a), figlio_lontano(sinistro(a)), figlio_lontano(destro(a)));
	}
	return NULL;
}

int main() {
	TipoAlbero albero = creaAlbBin(4, creaAlbBin(2, creaAlbBin(6, albBinVuoto(), albBinVuoto()), albBinVuoto()),
											creaAlbBin(3, creaAlbBin(1, albBinVuoto(), albBinVuoto()), albBinVuoto())); 
	stampaAlbero(albero);
	TipoAlbero ris = figlio_lontano(albero);

	return 0;
}