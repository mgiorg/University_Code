set RENNE;

param LatoX;
param LatoY;
param DistanzaMin;
param RaggioMin{RENNE};
param pi := 3.14159265358979;

var CentroRecintoX{RENNE} >= 0, <= LatoX;
var CentroRecintoY{RENNE} >= 0, <= LatoY;
var RaggioRecinto{i in RENNE} >= RaggioMin[i];

maximize area_tot:
 sum{i in RENNE} pi*RaggioRecinto[i]^2;

subject to bordo_X_1 {i in RENNE}:
 RaggioRecinto[i] <= CentroRecintoX[i];

subject to bordo_X_2 {i in RENNE}:
 CentroRecintoX[i] + RaggioRecinto[i] <= LatoX;

subject to bordo_Y_1 {i in RENNE}:
 RaggioRecinto[i] <= CentroRecintoY[i];

subject to bordo_Y_2 {i in RENNE}:
 CentroRecintoY[i] + RaggioRecinto[i] <= LatoY;

subject to recinti {i in RENNE, j in RENNE: i != j}:
 (CentroRecintoX[i]-CentroRecintoX[j])^2 + 
 (CentroRecintoY[i]-CentroRecintoY[j])^2 >=
 (RaggioRecinto[i] + RaggioRecinto[j] + DistanzaMin)^2;

