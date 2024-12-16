set FONTI;

param Domanda;
param Costo{FONTI};
param QtaMax{FONTI};
param CostoFisso{FONTI} default 0;
param M := Domanda;

var x{i in FONTI} >= 0, <= QtaMax[i];
var y{i in FONTI} binary;
var z_green1 binary;
var z_green2 binary;

minimize costo:
  sum{i in FONTI} ((Costo[i]/1000)*x[i] + CostoFisso[i]*y[i]);

subject to domanda:
  sum{i in FONTI} x[i] = Domanda;

subject to attivazione {i in FONTI}:
  x[i] <= QtaMax[i]*y[i];

subject to green1:
  x['petr']+x['carb'] <= 0.5*Domanda + z_green1*M;

subject to green2:
  x['sola']+x['eoli'] >= 0.2*Domanda - z_green2*M;

subject to log:
  z_green1 + z_green2 <= 1;

subject to tecnico1:
  y['idro'] + y['gas'] <= 1;

subject to tecnico3:
  x['petr'] >= 0.4*x['carb'];



