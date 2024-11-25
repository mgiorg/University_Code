set CENTRI;
set CLIENTI;

param costi_trasporto{CENTRI,CLIENTI};
param p;

var x{CENTRI} binary;
var y{CENTRI,CLIENTI} binary;
var z;

minimize costo_max: z;

subject to costi {j in CLIENTI}:
        z >= sum{i in CENTRI} costi_trasporto[i,j]*y[i,j];

subject to attivazione_clienti {j in CLIENTI}:
        sum{i in CENTRI} y[i,j] = 1;

subject to attivazione_p_centri:
        sum{i in CENTRI} x[i] = p;

subject to attivazione_centri {i in CENTRI, j in CLIENTI}:
        y[i,j] <= x[i];
