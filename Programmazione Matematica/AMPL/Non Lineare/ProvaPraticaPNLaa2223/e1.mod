param pi := 3.14159265358979;

var r >= 0.001;  # Raggio della base
var h >= 0.001;  # Altezza del cono

# Funzione obiettivo: Massimizzare il volume
maximize Volume: (1/3) * pi * r^2 * h;

# Vincolo: Superficie laterale più area della base <= 3
subject to SuperficieTotale:
    pi * r * sqrt(r^2 + h^2) + pi * r^2 <= 3;
