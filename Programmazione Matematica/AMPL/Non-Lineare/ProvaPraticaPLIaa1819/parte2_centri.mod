
set Citta ordered;

param CostoConnessione{Citta, Citta}; # Costo di connessione tra le città
param Capacita{Citta}; # Capacità del centro nella città
param Domanda{Citta}; # Domanda della città
param MaxCentri;

var Attivazione{Citta} binary; # 1 se il centro è attivato, 0 altrimenti
var Flusso{Citta, Citta} >= 0, <= 1; # Flusso assegnato tra città e centri
var DistanzaMassima;

minimize DistanzaMassimaTotale:
    DistanzaMassima;

# Vincoli di capacità
subject to CapacitaCentri {i in Citta}:
    sum{j in Citta} Flusso[i, j]*Domanda[i] <= Capacita[i] * Attivazione[i];

# Domanda soddisfatta
subject to SoddisfaDomanda {j in Citta}:
    sum{i in Citta} Flusso[i, j] = Domanda[j];

# Numero massimo di centri attivati
subject to NumeroMassimoCentri:
    sum{i in Citta} Attivazione[i] <= MaxCentri;

# Vincolo sulla distanza massima
subject to CalcoloDistanzaMassima {i in Citta, j in Citta}:
    DistanzaMassima >= CostoConnessione[i, j] * Flusso[i, j];
