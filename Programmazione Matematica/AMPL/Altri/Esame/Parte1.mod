set LUOGHI;
set POSIZIONI_POSSIBILI; 

param X {LUOGHI}; 
param Y {LUOGHI}; 
param max_distanza := 500; 

var z {POSIZIONI_POSSIBILI} binary; 
var coperto {LUOGHI} binary; 
var copre {LUOGHI, POSIZIONI_POSSIBILI} binary; 

param distanza {i in LUOGHI, j in POSIZIONI_POSSIBILI} :=
    sqrt((X[i] - X[j])^2 + (Y[i] - Y[j])^2);

minimize non_coperti:
    sum {i in LUOGHI} (1 - coperto[i]);

subject to collegamento_copre {i in LUOGHI, j in POSIZIONI_POSSIBILI}:
    copre[i,j] <= z[j];

subject to collegamento_coperto {i in LUOGHI}:
    coperto[i] <= sum {j in POSIZIONI_POSSIBILI} copre[i,j];

subject to limite_distanza {i in LUOGHI, j in POSIZIONI_POSSIBILI}:
    distanza[i,j] <= max_distanza + (1 - copre[i,j]) * 1e6;

subject to numero_antenne:
    sum {j in POSIZIONI_POSSIBILI} z[j] = 4;
