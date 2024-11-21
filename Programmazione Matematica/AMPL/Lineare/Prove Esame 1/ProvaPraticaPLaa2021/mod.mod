set ING;
set NUT;
set FAR;
set OLI;

param Costo{ING}; #Costo al chilo
param minGrammi{NUT};
param maxGrammi{NUT};
param Contenuto{ING,NUT}; #gNUT/100gING
param tegliaFarina; #g
param tegliaOlio; #g

var Var{ING} >= 0;

minimize costoTotale:
	sum{i in ING} Var[i]*(Costo[i]/1000);

subject to maxfarina :
	sum{f in FAR} Var[f] = tegliaFarina;
subject to maxoli :
	sum{o in OLI} Var[o] = tegliaOlio;
subject to qualita {n in NUT}:
	minGrammi[n] <= sum{i in ING} (Contenuto[i,n]/100)*Var[i] <= maxGrammi[n];
