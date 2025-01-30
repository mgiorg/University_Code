param lato_triangolo := 1;
param altezza_triangolo := sqrt(lato_triangolo^2 - (0.5 * lato_triangolo)^2);

var base >= 0, <= lato_triangolo;
var altezza >= 0;

maximize area: base * altezza;

subject to limite:
    altezza <= altezza_triangolo - base * altezza_triangolo / lato_triangolo;
