param L;   # Lunghezza della cella
param W;   # Larghezza della cella
param H;   # Altezza della cella
param V_batteria;  # Volume di ogni batteria

param pi := 3.14159265358979;

var r >= 0;  # Raggio della batteria (minimo 0.01 per evitare zero division)
var h >= 0, <= H;  # Altezza della batteria

# Variabili intere per il numero di batterie lungo le dimensioni
var n_x >= 0, integer;
var n_y >= 0, integer;
var n_h >= 0, integer;

# Funzione obiettivo: Massimizzare il numero totale di batterie
maximize TotaleBatterie: n_x * n_y * n_h;

# Vincolo: Volume di una batteria
subject to VolumeBatteria:
    h * pi * r^2 = V_batteria;

# Vincolo: Numero massimo lungo la lunghezza
subject to NumMaxLunghezza:
    n_x * 2 * r <= L;

# Vincolo: Numero massimo lungo la larghezza
subject to NumMaxLarghezza:
    n_y * 2 * r <= W;

# Vincolo: Numero massimo lungo l'altezza
subject to NumMaxAltezza:
    n_h * h <= H;
