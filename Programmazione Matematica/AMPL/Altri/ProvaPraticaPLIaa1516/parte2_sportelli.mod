set Comuni; # Insieme dei comuni
set ComuniASL within Comuni; # Insieme dei comuni con ASL
param Distanza{Comuni, Comuni}; # Matrice delle distanze tra i comuni
param NumSportelli; # Numero di sportelli da attivare

var x{ComuniASL} binary; # 1 se un comune con ASL ha uno sportello, 0 altrimenti
var y{ComuniASL, Comuni} binary; # 1 se il comune j è servito dallo sportello attivo in i
var DistanzaMax >= 0; # Distanza massima tra il comune più distante e il suo sportello

minimize Obiettivo:
    DistanzaMax;

# Devono essere attivati esattamente NumSportelli
subject to AttivaSportelli:
    sum{i in ComuniASL} x[i] = NumSportelli;

# Se C2 è attivato, allora anche C4 deve essere attivato
subject to VincoloAttivazioneC2C4:
    x["C2"] <= x["C4"];

# Ogni comune j deve essere servito da un solo sportello attivo
subject to AssegnazioneComuni {j in Comuni}:
    sum{i in ComuniASL} y[i, j] = 1;

# Un comune j può essere servito da i solo se i ha uno sportello attivo
subject to CollegamentoAttivazione {i in ComuniASL, j in Comuni}:
    y[i, j] <= x[i];

# La distanza massima deve essere maggiore o uguale alla distanza di ogni comune dal proprio sportello
subject to CalcoloDistanzaMassima {i in ComuniASL, j in Comuni}:
    DistanzaMax >= Distanza[i, j] * y[i, j];
