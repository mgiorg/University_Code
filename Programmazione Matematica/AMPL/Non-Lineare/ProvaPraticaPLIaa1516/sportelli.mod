set COMUNI_ASL;
set COMUNI_NO_ASL;
set COMUNI := COMUNI_ASL union COMUNI_NO_ASL;

param distanza{COMUNI,COMUNI};
param p;

var x{COMUNI_ASL} binary;
var y{COMUNI_ASL,COMUNI} binary;
var z;

minimize costo_max: z;

subject to costi {j in COMUNI}:
        z >= sum{i in COMUNI_ASL} distanza[i,j]*y[i,j];

subject to attivazione_clienti {j in COMUNI}:
        sum{i in COMUNI_ASL} y[i,j] = 1;

subject to attivazione_p_sportelli:
        sum{i in COMUNI_ASL} x[i] = p;

subject to attivazione_sportelli {i in COMUNI_ASL, j in COMUNI}:
        y[i,j] <= x[i];

subject to v1:
        x['C2'] <= x['C4'];
