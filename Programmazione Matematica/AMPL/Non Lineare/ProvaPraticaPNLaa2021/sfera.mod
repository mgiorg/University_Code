param superficie_cil;
param numero_sfe;
param pi := 4 * atan(1);

var raggio_sfe >= 0;

maximize volume: (4/3)*pi*raggio_sfe^3;

subject to superficie_max:
  2*pi*raggio_sfe * 2*numero_sfe*raggio_sfe <= superficie_cil;

