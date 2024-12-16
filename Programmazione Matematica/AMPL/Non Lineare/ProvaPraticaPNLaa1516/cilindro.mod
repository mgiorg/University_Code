param raggio_cono;
param altezza_cono;

var raggio >= 0, <= raggio_cono;
var altezza >= 0;

maximize volume: 3.14*altezza*raggio^2;

subject to limite: altezza <= altezza_cono * (1-(raggio/raggio_cono));
