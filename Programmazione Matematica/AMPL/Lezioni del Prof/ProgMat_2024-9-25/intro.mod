set INV;

param Costo{INV};
param Ricavo{INV};
param budget;

var x{INV} binary;

maximize output:
 budget + sum{i in INV} (Ricavo[i]-Costo[i])*x[i];

subject to limite:
 sum{i in INV} Costo[i]*x[i] <= budget;