set CULTIVAR;  # Tipi di olive
set REPARTI;   # Reparti

param Prezzo{CULTIVAR};       # Prezzo per 100 kg di olive
param QtaMin{CULTIVAR};       # Quantità minima acquistabile (in 100 kg)
param QtaMax{CULTIVAR};       # Quantità massima acquistabile (in 100 kg)
param Resa{CULTIVAR};         # Resa in litri di olio per 100 kg di olive
param Acidita{CULTIVAR};      # Percentuale di acidità
param OreMax{REPARTI};        # Ore massime disponibili per ciascun reparto
param Tempo{CULTIVAR, REPARTI}; # Tempi in ore per lavorare 100 kg di olive in ogni reparto
param ProduzioneMin;          # Quantità minima di olio da produrre (litri)
param AciditaMax;             # Percentuale massima di acidità ammessa

var x{CULTIVAR, REPARTI} >= 0;  # Quantità di olive lavorate (in 100 kg)

# Funzione obiettivo: Minimizzare il costo totale
minimize costo:
    sum{i in CULTIVAR, j in REPARTI} Prezzo[i] * x[i,j];

# Vincolo: Ore massime disponibili per ciascun reparto
subject to limite_reparti {j in REPARTI}:
    sum{i in CULTIVAR} Tempo[i,j] * x[i,j] <= OreMax[j];

# Vincolo: Produzione totale di olio (esattamente uguale alla richiesta)
subject to produzione_olio:
    sum{i in CULTIVAR, j in REPARTI} Resa[i] * x[i,j] = ProduzioneMin;

# Vincolo: Percentuale di acidità media non deve superare il limite
subject to vincolo_acidita:
    sum{i in CULTIVAR, j in REPARTI} Acidita[i] * Resa[i] * x[i,j] 
    <= AciditaMax * (sum{i in CULTIVAR, j in REPARTI} Resa[i] * x[i,j]);

# Vincolo: Quantità minima e massima per ciascun cultivar
subject to vincolo_quantita {i in CULTIVAR}:
    QtaMin[i] <= sum{j in REPARTI} x[i,j] <= QtaMax[i];

# Vincolo: Percentuale minima per il cultivar "Frantoio"
subject to vincolo_percentuale:
    sum{j in REPARTI} x['Frantoio',j] >= 0.1 * sum{i in CULTIVAR, j in REPARTI} x[i,j];