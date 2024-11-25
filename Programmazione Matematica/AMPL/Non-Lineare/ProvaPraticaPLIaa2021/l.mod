set Citta;                          # Set delle città
param K {Citta};                    # Capacità dei centri
param d {Citta};                    # Domanda delle città
param A {Citta};                    # Costi di attivazione
param c {Citta, Citta};             # Costi di collegamento

# Variabili
var y {Citta}, binary;              # 1 se il centro è attivo, 0 altrimenti
var x {Citta, Citta} >= 0, <= 1;          # Quantità servita dalla città i alla città j

# Funzione obiettivo: minimizzare i costi totali
minimize CostoTotale:
    sum {i in Citta} A[i] * y[i] + sum {i in Citta, j in Citta} c[i, j] * x[i, j];

# Vincoli
subject to Domanda {j in Citta}:
    sum {i in Citta} x[i, j] = 1;

subject to Capacita {i in Citta}:
    sum {j in Citta} d[j]*x[i, j] <= K[i] * y[i];

subject to AttivazioneCentri {i in Citta, j in Citta}:
	x[i, j] <= y[i];

subject to LatinaAprilia:
    y["Latina"] <= y["Aprilia"];
