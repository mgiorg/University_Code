set SOSTANZE;

param VitC{SOSTANZE};
param VitB{SOSTANZE};
param Sali{SOSTANZE};
param Costo{SOSTANZE};
param ToxAttesa{SOSTANZE};  # Tossicità attesa
param Varianza{SOSTANZE};   # Varianza tossicità
param CovRosaAloe := 0.1;   # Covarianza tra Rosa e Aloe

param PesoTotale := 10;     # Peso totale del prodotto
param CostoMax := 1.5;      # Costo massimo

param VitC_min := 0.7;
param VitB_min := 1.1;
param Sali_min := 2.1;
param ToxMax := 22;

var q{SOSTANZE} >= 0;  # Quantità di ciascuna sostanza

# Variabili frazionali
var frazione{SOSTANZE} >= 0;

# Funzione obiettivo: Minimizzare il rischio della tossicità
minimize Rischio:
    sum{i in SOSTANZE} Varianza[i] * (q[i] / PesoTotale)^2 +
    2 * CovRosaAloe * (q["Rosa"] / PesoTotale) * (q["Aloe"] / PesoTotale);

# Vincolo: Peso totale = 10 grammi
subject to VincoloPeso:
    sum{i in SOSTANZE} q[i] = PesoTotale;

# Vincolo: Costo totale <= 1.5 euro
subject to VincoloCosto:
    sum{i in SOSTANZE} Costo[i] * q[i] <= CostoMax;

# Vincoli: Quantità minime di microelementi
subject to VitC_minimo:
    sum{i in SOSTANZE} VitC[i] * q[i] >= VitC_min;

subject to VitB_minimo:
    sum{i in SOSTANZE} VitB[i] * q[i] >= VitB_min;

subject to Sali_minimo:
    sum{i in SOSTANZE} Sali[i] * q[i] >= Sali_min;

# Vincolo: Tossicità attesa <= 22 microgrammi
subject to TossicitaAttesa:
    sum{i in SOSTANZE} ToxAttesa[i] * q[i] <= ToxMax;
