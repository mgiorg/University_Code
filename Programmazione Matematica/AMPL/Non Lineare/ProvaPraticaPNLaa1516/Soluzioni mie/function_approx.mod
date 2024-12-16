
# File: function_approx.mod

# Sets and Parameters
set POINTS;  # Set dei punti dati
param x1 {POINTS};
param x2 {POINTS};
param y {POINTS};

# Variabili per il modello lineare
var m1;
var m2;
var q;
var error {POINTS};

# Variabili per il modello quadratico
var a1;
var a2;
var b1;
var b2;
var c;
var quad_error {POINTS};

# Modello lineare: minimizzazione errore quadratico
minimize LinearError: sum {p in POINTS} error[p]^2;

subject to LinearApproximation {p in POINTS}:
    error[p] = y[p] - (m1 * x1[p] + m2 * x2[p] + q);

# Modello quadratico: minimizzazione errore quadratico
minimize QuadraticError: sum {p in POINTS} quad_error[p]^2;

subject to QuadraticApproximation {p in POINTS}:
    quad_error[p] = y[p] - (a1 * x1[p]^2 + a2 * x2[p]^2 + b1 * x1[p] + b2 * x2[p] + c);
