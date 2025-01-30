set Citta ordered;  

param x_citta{Citta};  
param y_citta{Citta}; 
param raggio_max;  

var x_punto{Citta};  
var y_punto{Citta};

minimize PercorsoTotale:
    (x_punto[1]^2) + (y_punto[1]^2) +
    sum{i in 2..13} ((x_punto[i] - x_punto[i-1])^2 + 
    				 (y_punto[i] - y_punto[i-1])^2);
		
subject to DistanzaMassima{i in Citta}:
	((x_citta[i]-x_punto[i])^2) + ((y_citta[i]-y_punto[i])^2) <= raggio_max^2;
    
    
