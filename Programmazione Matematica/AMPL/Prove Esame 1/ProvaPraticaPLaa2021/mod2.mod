set ING;
set NUT;
set FAR;
set OLI;
set COMPL;

param Costo{ING}; #Costo al chilo
param ub{ING};
param minGrammi{NUT};
param maxGrammi{NUT};
param Contenuto{ING,NUT}; #gNUT/100gING
param tegliaFarina; #g
param tegliaOlio; #g

var Var{i in ING} >= 0, <= ub[i];

minimize costoTotale:
	sum{i in ING} Var[i]*(Costo[i]/1000);

subject to maxfarina :
	sum{f in FAR} Var[f] = tegliaFarina;
subject to maxoli :
	sum{o in OLI} Var[o] = tegliaOlio;
subject to qualita {n in NUT}:
	minGrammi[n] <= sum{i in ING} (Contenuto[i,n]/100)*Var[i] <= maxGrammi[n];
subject to maxCompl:
	sum{c in COMPL} Var[c] >= 0.5*sum{f in FAR}Var[f];
