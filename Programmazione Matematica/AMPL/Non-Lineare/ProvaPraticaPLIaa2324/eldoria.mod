set NANI;
set ELFI;
set GUERRIERI;
set MAGHI;
set PERSONAGGI := NANI union ELFI union GUERRIERI union MAGHI;
set QUALITA;
set DIFETTI;
set CARATTERISTICHE := QUALITA union DIFETTI;

param Valore{PERSONAGGI,CARATTERISTICHE};
param Costo{PERSONAGGI};
param Qualita_Min{QUALITA};
param Difetto_Max{DIFETTI};
param Potenziamenti_Max{PERSONAGGI};
param Costo_potenziamento_lieve;
param Costo_potenziamento_medio;
param Costo_potenziamento_forte;
param Valore_potenziamento_lieve;
param Valore_potenziamento_medio;
param Valore_potenziamento_forte;

var x{PERSONAGGI} binary;
var potenziamento_lieve{PERSONAGGI,CARATTERISTICHE} binary;
var potenziamento_medio{PERSONAGGI,CARATTERISTICHE} binary;
var potenziamento_forte{PERSONAGGI,CARATTERISTICHE} binary;

minimize Costo_totale:
 sum{i in PERSONAGGI} Costo[i]*x[i] +
 sum{i in PERSONAGGI, j in CARATTERISTICHE}
  (Costo_potenziamento_lieve*potenziamento_lieve[i,j] +
   Costo_potenziamento_medio*potenziamento_medio[i,j] +
   Costo_potenziamento_forte*potenziamento_forte[i,j]);

subject to controllo_potenziamenti {i in PERSONAGGI}:
 sum{j in CARATTERISTICHE} (potenziamento_lieve[i,j] +
                            potenziamento_medio[i,j] +
                            potenziamento_forte[i,j])
 <= Potenziamenti_Max[i]*x[i];

subject to controllo_qualita {j in QUALITA}:
 sum{i in PERSONAGGI} (Valore[i,j]*x[i] +
  Valore_potenziamento_lieve*potenziamento_lieve[i,j] +
  Valore_potenziamento_medio*potenziamento_medio[i,j] +
  Valore_potenziamento_forte*potenziamento_forte[i,j])
 >= Qualita_Min[j];

subject to controllo_difetti {j in DIFETTI}:
 sum{i in PERSONAGGI} (Valore[i,j]*x[i] -
  Valore_potenziamento_lieve*potenziamento_lieve[i,j] -
  Valore_potenziamento_medio*potenziamento_medio[i,j] -
  Valore_potenziamento_forte*potenziamento_forte[i,j])
 <= Difetto_Max[j];

subject to naniEdElfi:
 sum{i in NANI} x[i] = sum{i in ELFI} x[i];

subject to maghiEGuerrieri:
 sum{i in GUERRIERI} x[i] <= sum{i in MAGHI} x[i];
