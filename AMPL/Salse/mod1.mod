set PROD;
set ING;

param Prezzo{PROD};
param CostoBase{PROD};
param Q_Prodotto{PROD};
param A_Min{PROD};
param A_Max{PROD};
param D_Min{PROD};
param D_Max{PROD};
param U_Minimo{PROD};
param CostoIng{ING};
param Dolcezza{ING};
param Acidita{ING};
param Umami{ING};

var Quantita{ING,PROD} >= 0;

maximize profitto:
	sum{p in PROD} (Prezzo[p]-CostoBase[p])*Q_Prodotto[p] 
	- sum{p in PROD, i in ING} CostoIng[i]*Quantita[i,p];

subject to maxIngredienti {j in PROD}:
	sum{i in ING} Quantita[i,j] >= Q_Prodotto[j];
subject to maxAcid{j in PROD}:
	sum{i in ING} Acidita[i]*Quantita[i,j] <= A_Max[j]*Q_Prodotto[j];
subject to minAcid{j in PROD}:
	sum{i in ING} Acidita[i]*Quantita[i,j] >= A_Min[j]*Q_Prodotto[j];
subject to minDolc{j in PROD}:
	sum{i in ING} Dolcezza[i]*Quantita[i,j] >= D_Min[j]*Q_Prodotto[j];
subject to maxDolc{j in PROD}:
	sum{i in ING} Dolcezza[i]*Quantita[i,j] <= D_Max[j]*Q_Prodotto[j];
subject to minUmami{j in PROD}:
	sum{i in ING} Umami[i]*Quantita[i,j] >= U_Minimo[j]*Q_Prodotto[j];