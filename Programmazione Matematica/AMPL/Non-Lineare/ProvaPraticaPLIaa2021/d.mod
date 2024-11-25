# Set e parametri
set PRODOTTI;
param p {PRODOTTI};      # Profitto unitario
param F {PRODOTTI};      # Costo fisso
param u {PRODOTTI};      # Quantità massima

# Set derivati
set ACQUE;               # Prodotti di tipo acqua
set BIBITE;              # Prodotti di tipo bibita
set SNACK;               # Prodotti di tipo snack

# Variabili
var x {PRODOTTI} >= 0, integer;    # Quantità di prodotti
var y {PRODOTTI}, binary;          # Scelta del prodotto

# Funzione obiettivo
maximize Profitto:
    sum {i in PRODOTTI} (p[i] * x[i] - F[i] * y[i]);

# Vincoli
subject to Capacita:
    sum {i in PRODOTTI} x[i] <= 180;

subject to Bevande:
    sum {i in ACQUE} x[i] + sum {i in BIBITE} x[i] >= 110;

subject to Snack:
    sum {i in SNACK} x[i] >= 50;

subject to ProporzioneAcque:
    sum {i in ACQUE} x[i] >= 0.6 * sum {i in BIBITE} x[i];

subject to MaxSnack:
    sum {i in SNACK} y[i] <= 3;

subject to QuantitaMax {i in PRODOTTI}:
    x[i] <= u[i] * y[i];

subject to SelezioneProdotto {i in PRODOTTI}:
    y[i] >= x[i] / u[i];
