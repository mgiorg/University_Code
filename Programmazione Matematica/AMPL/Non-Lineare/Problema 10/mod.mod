set LAVORI;  # Set dei lavori (es. LAV1, LAV2, LAV3)
set CANDIDATI;  # Set dei candidati (es. C1, C2, C3, C4, C5)

param Costo{CANDIDATI, LAVORI};  # Costo di assegnazione candidato-lavoro

# Variabili binarie: 1 se il candidato c è assegnato al lavoro l, 0 altrimenti
var Assegnazione{CANDIDATI, LAVORI} binary;

# Funzione obiettivo: minimizzare il costo totale di assegnazione
minimize CostoTotale:
    sum {c in CANDIDATI, l in LAVORI} Costo[c, l] * Assegnazione[c, l];

# Ogni lavoro deve avere un candidato assegnato
subject to UnCandidatoPerLavoro {l in LAVORI}:
    sum {c in CANDIDATI} Assegnazione[c, l] = 1;

# Ogni candidato può essere assegnato a un solo lavoro
subject to UnLavoroPerCandidato {c in CANDIDATI}:
    sum {l in LAVORI} Assegnazione[c, l] <= 1;

# Condizione: C1 può essere assunto solo se C2 è assunto
subject to CondizioneC1_C2:
    sum {l in LAVORI} Assegnazione["C1", l] <= sum {l in LAVORI} Assegnazione["C2", l];

# Condizione: Non si possono assumere sia C4 sia C5
subject to CondizioneC4_C5:
    sum {l in LAVORI} Assegnazione["C4", l] + sum {l in LAVORI} Assegnazione["C5", l] <= 1;
