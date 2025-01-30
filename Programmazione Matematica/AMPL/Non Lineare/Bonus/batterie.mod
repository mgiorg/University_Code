param raggio_cono;
param altezza_cono;
param volume_batteria;  

param pi := 3.14159265358979;

var raggio_batteria >= 0;
var altezza_batteria >= 0;
var n_batterie integer >= 0;

s.t. VolumeBatteria:
    pi * raggio_batteria^2 * altezza_batteria = volume_batteria;

s.t. ConoContenitore:
    n_batterie * (pi * raggio_batteria^2 * altezza_batteria) <=
    (1/3) * pi * raggio_cono^2 * altezza_cono;

s.t. AltezzaConoVincolo:
    altezza_batteria <= altezza_cono;

s.t. RaggioConoVincolo:
    2 * raggio_batteria <= raggio_cono;

# Obiettivo
maximize BatterieTotali:
    n_batterie;
