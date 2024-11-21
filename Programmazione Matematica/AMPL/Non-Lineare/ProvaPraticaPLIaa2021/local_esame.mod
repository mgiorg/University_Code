set CENTRI;

param f{CENTRI};
param costi_trasporto{CENTRI,CENTRI};
param domanda{CENTRI};
param capacita{CENTRI};

var x{CENTRI} binary;
var y{CENTRI,CENTRI} >= 0, <= 1;

minimize costi:
        sum{i in CENTRI} f[i]*x[i] + sum{i in CENTRI, j in CENTRI} costi_trasporto[i,j]*y[i,j];

subject to attivazione_clienti {j in CENTRI}:
        sum{i in CENTRI} y[i,j] = 1;

subject to limite_capacita {i in CENTRI}:
        sum{j in CENTRI} domanda[j]*y[i,j] <= capacita[i]*x[i];

subject to attivazione_centri {i in CENTRI, j in CENTRI}:
        y[i,j] <= x[i];

subject to dipendenza:
        x['Lat'] <= x['Apr'];
