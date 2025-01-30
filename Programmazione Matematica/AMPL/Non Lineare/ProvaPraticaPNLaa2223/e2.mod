param a1 := 10;  # Coefficiente della domanda prodotto 1
param a2 := 6;   # Coefficiente della domanda prodotto 2

var q1 >= 0;  # Quantità prodotto 1
var q2 >= 0;  # Quantità prodotto 2

# Prezzi dei prodotti
var p1 = a1 - 0.002 * q1;
var p2 = a2 - 0.002 * q2;

# Funzione obiettivo: Massimizzare il profitto
maximize Profitto: p1 * q1 + p2 * q2;

# Vincolo: Prezzo del prodotto 2 non supera metà del prezzo del prodotto 1
subject to VincoloPrezzo:
    p2 <= 0.5 * p1;
