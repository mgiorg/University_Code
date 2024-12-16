param lato_base_pir;
param altezza_pir;

var lato_cubo >= 0, <= lato_base_pir;

maximize volume: lato_cubo^3;

subject to limite: lato_cubo <= altezza_pir*(lato_base_pir - lato_cubo)/lato_base_pir;

