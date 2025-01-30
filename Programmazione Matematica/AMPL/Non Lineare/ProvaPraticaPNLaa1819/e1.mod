# Modello per massimizzare il volume di un cubo inscritto in una piramide
param lato_base;   # Lato della base della piramide
param altezza_piramide;  # Altezza della piramide

var s >= 0;  # Lato del cubo

maximize VolumeCubo: s^3;

subject to VincoloBase:
    s <= lato_base;

subject to VincoloAltezza:
    s <= altezza_piramide - (altezza_piramide / lato_base) * s;
