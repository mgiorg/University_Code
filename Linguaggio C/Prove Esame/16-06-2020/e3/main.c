#include "funzioni.c"

/**
         4 
       _/ \_   
      /     \  
     2       3 
     |       |   
    /       /    
   6       1

 		 1 
       _/ \_   
      /     \  
     2       1 
     |       |   
    /       /    
   6       1     
*/
TipoAlbero controlloNodi(TipoAlbero a) {
	TipoAlbero nuovo = creaAlbBin(radice(a), sinistro(a), destro(a));
	if(estFoglia(a)) return nuovo;
	if(estVuoto(a)) return nuovo;
	if(!estVuoto(sinistro(a))) {
	if (sinistro(a) != NULL && destro(a) == NULL) {
        	nuovo -> sinistro = alberoPiuDistanzaNodo_aux(sinistro(a));
          	return nuovo;
        }
      	else if (sinistro(a) == NULL && destro(a) != NULL) {
        	nuovo -> destro = alberoPiuDistanzaNodo_aux(destro(a));
          	return nuovo;
        }
      	else {  	         	
          	nuovo -> destro = alberoPiuDistanzaNodo_aux(destro(a));          	
          	nuovo -> sinistro = alberoPiuDistanzaNodo_aux(sinistro(a));        	
          	return nuovo;
        }
	}
}

void nodoDivisibile(TipoAlbero a) {
    // IMPLEMENTARE QUI LA SOLUZIONE DELL'ESERCIZIO
	
	a = controlloNodi(a);

    return;
}

int main() {


	return 0;
}