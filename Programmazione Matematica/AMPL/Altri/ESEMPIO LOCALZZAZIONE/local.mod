set CENTRI;
set CLIENTI;

param costi_fissi{CENTRI};
param costi_trasporto{CENTRI,CLIENTI};

var x{CENTRI} binary;
var y{CENTRI,CLIENTI} binary;

minimize costi:
        sum{i in CENTRI} costi_fissi[i]*x[i] +
        sum{i in CENTRI, j in CLIENTI} costi_trasporto[i,j]*y[i,j];

subject to attivazione_clienti {j in CLIENTI}:
        sum{i in CENTRI} y[i,j] = 1;

subject to attivazione_centri {i in CENTRI, j in CLIENTI}:
        y[i,j] <= x[i];
