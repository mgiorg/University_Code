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
void controlloNodi(TipoAlbero a) {
	if(estFoglia(a)) return;
	if(estVuoto(a)) return;
	if(!estVuoto(sinistro(a))) 
		if(radice(sinistro(a))%radice(a) == 0) 
			a = creaAlbBin(1, sinistro(a), destro(a)); 
		
	else if(!estVuoto(destro(a))) 
		if(radice(destro(a))%radice(a) == 0) 
			a = creaAlbBin(1, sinistro(a), destro(a)); 
	controlloNodi(sinistro(a));
	controlloNodi(destro(a));
	return;
}

void nodoDivisibile(TipoAlbero a) {
    // IMPLEMENTARE QUI LA SOLUZIONE DELL'ESERCIZIO
	
	controlloNodi(a);

    return;
}

int main() {


	return 0;
}