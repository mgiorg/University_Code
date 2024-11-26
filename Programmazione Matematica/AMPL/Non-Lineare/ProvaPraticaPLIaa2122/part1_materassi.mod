set MODELLI; # Modelli di materassi
set MATERIALI; # Materiali disponibili
set SPESSORI; # Spessori disponibili

param prezzo_base {MODELLI}; # Prezzo base per modello
param rincaro_materiale {MATERIALI}; # Fattore di rincaro per materiale
param rincaro_spessore {SPESSORI}; # Fattore di rincaro per spessore
param costo_fisso {MODELLI}; # Costo fisso per modello

param min_qta := 100; # Quantità minima per ogni tipologia
param totale_materassi; # Totale dei materassi da produrre

var x {MODELLI, MATERIALI, SPESSORI} integer, >= 0; # Quantità prodotta
var y {MODELLI, MATERIALI, SPESSORI} binary; # Se la tipologia è prodotta

# Variabili binarie per vincoli opzionali
var v1 binary; # Se il totale dei materassi nature è >= 30% della produzione totale
var v2 binary; # Se non si producono materassi comfort in memory da 40 cm
var v3 binary; # Se si producono al massimo 5 tipologie di essential

maximize profitto:
    sum {i in MODELLI, j in MATERIALI, k in SPESSORI} 
        (prezzo_base[i] * rincaro_materiale[j] * rincaro_spessore[k] * x[i,j,k]
         - costo_fisso[i] * y[i,j,k]);

# Vincolo sulla produzione totale
subject to totale_produzione:
    sum {i in MODELLI, j in MATERIALI, k in SPESSORI} x[i,j,k] = totale_materassi;

# Vincolo sulla quantità minima per ogni tipologia
subject to Attivazione1 {i in MODELLI, j in MATERIALI, k in SPESSORI}:
    x[i,j,k] >= min_qta * y[i,j,k];
    
subject to Attivazione2 {i in MODELLI, j in MATERIALI, k in SPESSORI}:
    x[i,j,k] <= totale_materassi * y[i,j,k];

# Almeno 2 tipologie diverse per modello
subject to almeno_due_per_modello {i in MODELLI}:
    sum {j in MATERIALI, k in SPESSORI} y[i,j,k] >= 2;

# Almeno 4 tipologie diverse per materiale
subject to almeno_quattro_per_materiale {j in MATERIALI}:
    sum {i in MODELLI, k in SPESSORI} y[i,j,k] >= 4;

# Almeno 3 tipologie diverse per spessore
subject to almeno_tre_per_spessore {k in SPESSORI}:
    sum {i in MODELLI, j in MATERIALI} y[i,j,k] >= 3;

# Vincolo per soddisfare almeno uno dei tre opzionali
subject to vincolo_nature:
    sum {j in MATERIALI, k in SPESSORI} x["nature",j,k] >= 
    0.3 * totale_materassi - v1 * totale_materassi;

subject to vincolo_comfort:
    y["comfort", "memory", "40 cm"] <= 0 + totale_materassi*v2;

subject to vincolo_essential:
    sum {j in MATERIALI, k in SPESSORI} y["essential",j,k] <= 
    5 + 1000*v3;

# Almeno uno dei tre vincoli deve essere rispettato
subject to almeno_uno_opzionale:
    v1 + v2 + v3 <= 2;
