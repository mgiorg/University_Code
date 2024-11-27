set PERSONAGGI; # Personaggi disponibili
set CARATTERISTICHE := {"forza", "resistenza", "magia", "astuzia", "codardia", "corruzione"};
set TIPI_POTENZIAMENTO := {"lieve", "medio", "forte"};

param costo {PERSONAGGI}; # Costo base di ogni personaggio
param base {PERSONAGGI, CARATTERISTICHE}; # Valori base delle caratteristiche
param max_potenziamenti {PERSONAGGI}; # Numero massimo di potenziamenti per personaggio

param costo_potenziamento {TIPI_POTENZIAMENTO}; # Costi dei potenziamenti
param miglioramento {TIPI_POTENZIAMENTO}; # Valore di incremento per forza, resistenza, magia, astuzia
param riduzione {TIPI_POTENZIAMENTO}; # Valore di decremento per codardia e corruzione

param limiti_min {CARATTERISTICHE}; # Valori minimi richiesti per le caratteristiche
param limiti_max {CARATTERISTICHE}; # Valori massimi permessi per le caratteristiche

var x {PERSONAGGI} binary; # Se il personaggio è scelto
var potenziamento {PERSONAGGI, CARATTERISTICHE, TIPI_POTENZIAMENTO} binary; # Se un potenziamento è applicato

# Funzione obiettivo: Minimizzare il costo totale
minimize costo_totale:
    sum {p in PERSONAGGI} costo[p] * x[p] +
    sum {p in PERSONAGGI, c in CARATTERISTICHE, t in TIPI_POTENZIAMENTO} 
        potenziamento[p,c,t] * costo_potenziamento[t];

# Vincoli per garantire i requisiti minimi delle caratteristiche (forza, resistenza, magia, astuzia)
subject to caratteristica_minima {c in {"forza", "resistenza", "magia", "astuzia"}}:
    sum {p in PERSONAGGI} (
        base[p,c] * x[p] + sum {t in TIPI_POTENZIAMENTO} miglioramento[t] * potenziamento[p,c,t]
    ) >= limiti_min[c];

# Vincoli per limitare i valori massimi di codardia e corruzione
subject to caratteristica_massima {c in {"codardia", "corruzione"}}:
    sum {p in PERSONAGGI} (
        base[p,c] * x[p] - sum {t in TIPI_POTENZIAMENTO} riduzione[t] * potenziamento[p,c,t]
    ) <= limiti_max[c];

# Ogni personaggio può essere potenziato solo se è scelto
subject to potenziamento_logico {p in PERSONAGGI, c in CARATTERISTICHE, t in TIPI_POTENZIAMENTO}:
    potenziamento[p,c,t] <= x[p];

# Ogni caratteristica può essere potenziata una sola volta per tipo
subject to singolo_potenziamento {p in PERSONAGGI, c in CARATTERISTICHE}:
    sum {t in TIPI_POTENZIAMENTO} potenziamento[p,c,t] <= 1;

# Limiti sul numero massimo di potenziamenti per personaggio
subject to limite_potenziamenti {p in PERSONAGGI}:
    sum {c in CARATTERISTICHE, t in TIPI_POTENZIAMENTO} potenziamento[p,c,t] <= max_potenziamenti[p];

# Equilibrio tra nani ed elfi
subject to equilibrio_nani_elfi:
    sum {p in PERSONAGGI: p in {"Thrain", "Gimble", "Dolgrin"}} x[p] =
    sum {p in PERSONAGGI: p in {"Lirel", "Eldara", "Silvian"}} x[p];

# Guerrieri non possono superare il numero di maghi
subject to guerrieri_maghi:
    sum {p in PERSONAGGI: p in {"Aldric", "Lyra"}} x[p] <= 
    sum {p in PERSONAGGI: p in {"Morgana", "Varian"}} x[p];
