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

void nodoDivisibile(TipoAlbero a) {
    if(estVuoto(a) || estFoglia(a)) return;
	if(sinistro(a) != NULL)  {
		printf("Sinistro\n");
		if(radice(sinistro(a)) != 0 && radice(a)%radice(sinistro(a)) == 0) {
			a-> info = 1; 
			printf("Valore cambiato\n");
		}
    }
		
	if(destro(a) != NULL) { 
		printf("Destro\n");
		if(radice(destro(a)) != 0 && radice(a)%radice(destro(a)) == 0) {
			a-> info = 1; 
			printf("Valore cambiato\n");
		}
    }
	if(sinistro(a) != NULL)
    	{nodoDivisibile(sinistro(a));}
	if(destro(a) != NULL)
    	{nodoDivisibile(destro(a));}
}

int main() {
	//TipoAlbero albero = creaAlbBin(4, creaAlbBin(2, creaAlbBin(6, albBinVuoto(), albBinVuoto()), albBinVuoto()),
											//creaAlbBin(3, creaAlbBin(1, albBinVuoto(), albBinVuoto()), albBinVuoto())); 
	TipoAlbero albero = albBinVuoto();
	nodoDivisibile(albero);


	return 0;
}