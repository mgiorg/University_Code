set CENTRI;
set CLIENTI;

param costi_fissi{CENTRI};
param costi_trasporto{CENTRI,CLIENTI};
param domanda{CLIENTI};
param capacita{CENTRI};

var x{CENTRI} binary;
var y{CENTRI,CLIENTI} >= 0, <= 1;

minimize costi:
        sum{i in CENTRI} costi_fissi[i]*x[i] +
        sum{i in CENTRI, j in CLIENTI} costi_trasporto[i,j]*y[i,j];

subject to attivazione_clienti {j in CLIENTI}:
        sum{i in CENTRI} y[i,j] = 1;

subject to limite_capacita {i in CENTRI}:
        sum{j in CLIENTI} domanda[j]*y[i,j] <= capacita[i]*x[i];

subject to attivazione_centri {i in CENTRI, j in CLIENTI}:
        y[i,j] <= x[i];
