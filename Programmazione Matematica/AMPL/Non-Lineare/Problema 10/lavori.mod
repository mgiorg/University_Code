set CANDIDATI;
set LAVORI;

param Costo{CANDIDATI,LAVORI};

var x{CANDIDATI,LAVORI} binary;

minimize costo_tot:
 sum{i in CANDIDATI,j in LAVORI} Costo[i,j]*x[i,j];

subject to lavori_coperti {j in LAVORI}:
 sum{i in CANDIDATI} x[i,j] = 1;

subject to candidati {i in CANDIDATI}:
 sum{j in LAVORI} x[i,j] <= 1;

subject to logico1:
 sum{j in LAVORI} x['C1',j] <= sum{j in LAVORI} x['C2',j];

subject to logico2:
 sum{j in LAVORI} x['C4',j] + sum{j in LAVORI} x['C5',j] <= 1;
