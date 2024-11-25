
set PERSONAGGI;  # Set dei personaggi disponibili
set CARATTERISTICHE;  # Set delle caratteristiche (forza, resistenza, magia, astuzia, codardia, corruzione)
set POTENZIAMENTI;  # Tipologie di potenziamento (lieve, medio, forte)

param costo{PERSONAGGI};  # Costo base di ciascun personaggio
param caratteristica{PERSONAGGI, CARATTERISTICHE};  # Valori iniziali delle caratteristiche
param limite_pot{PERSONAGGI};  # Limite massimo di potenziamenti per ciascun personaggio
param costo_pot{POTENZIAMENTI};  # Costo dei potenziamenti
param effetto_pot{POTENZIAMENTI, CARATTERISTICHE};  # Effetto dei potenziamenti
param richiesto{CARATTERISTICHE};  # Valori minimi richiesti
param max_ammissibile{CARATTERISTICHE};  # Valori massimi ammissibili

var x{PERSONAGGI} binary;  # Variabile: selezione del personaggio
var y{PERSONAGGI, POTENZIAMENTI, CARATTERISTICHE} binary;  # Potenziamento applicato

# Funzione obiettivo: Minimizzare il costo totale
minimize costo_totale:
    sum {i in PERSONAGGI} costo[i] * x[i] +
    sum {i in PERSONAGGI, p in POTENZIAMENTI, c in CARATTERISTICHE} costo_pot[p] * y[i, p, c];

# Vincoli di requisiti sulle caratteristiche
subject to requisiti_minimi {c in {"forza", "resistenza", "magia", "astuzia"}}:
    sum {i in PERSONAGGI} (caratteristica[i, c] * x[i] +
                            sum {p in POTENZIAMENTI} effetto_pot[p, c] * y[i, p, c]) >= richiesto[c];

subject to requisiti_massimi {c in {"codardia", "corruzione"}}:
    sum {i in PERSONAGGI} (caratteristica[i, c] * x[i] +
                            sum {p in POTENZIAMENTI} effetto_pot[p, c] * y[i, p, c]) <= max_ammissibile[c];

# Vincoli sul numero di razze
subject to equilibrio_nani_elfi:
    sum {i in {"Thrain", "Gimble", "Dolgrin"}} x[i] = 
    sum {i in {"Lirel", "Eldara", "Silvian"}} x[i];

subject to guerrieri_vs_maghi:
    sum {i in {"Aldric", "Lyra"}} x[i] <= 
    sum {i in {"Morgana", "Varian"}} x[i];

# Limitazioni sui potenziamenti
subject to limite_potenziamenti {i in PERSONAGGI}:
    sum {p in POTENZIAMENTI, c in CARATTERISTICHE} y[i, p, c] <= limite_pot[i];

# Attivazione dei potenziamenti
subject to attivazione_potenziamenti {i in PERSONAGGI, p in POTENZIAMENTI, c in CARATTERISTICHE}:
    y[i, p, c] <= x[i];
