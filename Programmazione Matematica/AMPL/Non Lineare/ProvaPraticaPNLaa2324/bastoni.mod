set FABBRICHE;

param FabbricaX{FABBRICHE};
param FabbricaY{FABBRICHE};
param DistanzaBastoni;

var Bastone1X >= 0;
var Bastone1Y >= 0;
var Bastone2X >= 0;
var Bastone2Y >= 0;
var DistanzaMax{FABBRICHE} >= 0;

minimize distanze:
 sum{i in FABBRICHE} DistanzaMax[i];

subject to distanze_minime1 {i in FABBRICHE}:
 DistanzaMax[i]^2 >= (FabbricaX[i]-Bastone1X)^2+
                     (FabbricaY[i]-Bastone1Y)^2;

subject to distanze_minime2 {i in FABBRICHE}:
 DistanzaMax[i]^2 >= (FabbricaX[i]-Bastone2X)^2+
                     (FabbricaY[i]-Bastone2Y)^2;

subject to distanza_bastoni:
 (Bastone1X-Bastone2X)^2 +
 (Bastone1Y-Bastone2Y)^2 >= DistanzaBastoni^2;
