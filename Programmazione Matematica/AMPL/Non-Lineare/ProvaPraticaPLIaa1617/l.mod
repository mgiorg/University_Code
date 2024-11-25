set INGREDIENTI;                    # Set degli ingredienti
param costo {INGREDIENTI};          # Costo per kg
param proteine {INGREDIENTI};       # Proteine per kg
param grassi_insaturi {INGREDIENTI};# Grassi insaturi per kg
param grassi_saturi {INGREDIENTI};  # Grassi saturi per kg
param sale {INGREDIENTI};           # Sale per kg
param categoria {INGREDIENTI};      # Categoria: 1 = magra, 2 = grassa, 3 = saporita

# Variabili
var q {INGREDIENTI} >= 0;           # Quantità di ciascun ingrediente in grammi
var y {INGREDIENTI}, binary;        # 1 se l'ingrediente è selezionato, 0 altrimenti
var z, binary;                      # 1 se le proteine sono inferiori a 46 g, 0 altrimenti

# Funzione obiettivo: minimizzare il costo totale
minimize CostoTotale:
    sum {i in INGREDIENTI} costo[i] * q[i] / 1000;

# Vincoli
subject to PesoTotale:
    sum {i in INGREDIENTI} q[i] = 100;

subject to Proteine:
    35 <= sum {i in INGREDIENTI} proteine[i] * q[i] / 1000 <= 60;

subject to GrassiInsaturi:
    40 <= sum {i in INGREDIENTI} grassi_insaturi[i] * q[i] / 1000 <= 50;

subject to GrassiSaturi:
    sum {i in INGREDIENTI} grassi_saturi[i] * q[i] / 1000 <= 19;

subject to Sale:
    sum {i in INGREDIENTI} sale[i] * q[i] / 1000 <= 0.6;

subject to AlmenoUnIngredientePerCategoria {c in 1..3}:
    sum {i in INGREDIENTI: categoria[i] == c} y[i] >= 1;

subject to MaxDueIngredientiPerCategoria {c in 1..3}:
    sum {i in INGREDIENTI: categoria[i] == c} y[i] <= 2;

subject to SceltaIngrediente {i in INGREDIENTI}:
    q[i] <= 100 * y[i];

subject to LardoFegato:
    y["lardo"] + y["fegato"] <= 1;

# Variabile ausiliaria per la condizione proteine
subject to CondizioneProteine1:
    sum {i in INGREDIENTI} proteine[i] * q[i] / 1000 >= 46 - 46 * z;

subject to CondizioneProteine2:
    sum {i in INGREDIENTI: categoria[i] == 1} q[i] >= 60 * z;

subject to CondizioneProteine3:
    sum {i in INGREDIENTI} sale[i] * q[i] / 1000 <= 0.5 + 0.1 * (1 - z);
