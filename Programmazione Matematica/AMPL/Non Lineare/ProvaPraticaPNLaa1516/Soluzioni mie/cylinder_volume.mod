
# File: cylinder_volume.mod

# Parameters
param H_cone;  # Altezza del cono (cm)
param R_cone;  # Raggio di base del cono (cm)
param pi := 3.14;

# Variables
var h >= 0, <= H_cone;  # Altezza del cilindro (cm)
var r >= 0, <= R_cone;  # Raggio della base del cilindro (cm)

# Objective: Massimizzare il volume del cilindro inscritto
maximize Volume: pi * r^2 * h;

# Vincolo: Il cilindro deve essere inscritto nel cono
subject to Inscribed:
    h <= H_cone * (1-(r/R_cone));
