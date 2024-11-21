set PROD;
set REP;
set MP;
set CITTA;

param l{PROD,CITTA} >= 0;
param u{i in PROD, j in CITTA} >= l[i,j];
param ConsMinRep{PROD,REP};
param MaxOreRep{CITTA,REP};
param ConsMP{PROD,MP};
param DispMP{CITTA,MP};
param Prez{PROD};
param PercMinProd{PROD};
param PercMaxProd{PROD};
param PercMinCitta{CITTA};
param PercMaxCitta{CITTA};

var x{i in PROD, j in CITTA} >= l[i,j], <= u[i,j];

maximize ricavo:
  sum{i in PROD, j in CITTA} Prez[i]*x[i,j];

s.t. risorsa_reparti {j in CITTA, k in REP}:
  sum{i in PROD} ConsMinRep[i,k]*x[i,j] <= 60*MaxOreRep[j,k];

s.t. risorsa_mp {j in CITTA, t in MP}:
  sum{i in PROD} ConsMP[i,t]*x[i,j] <= DispMP[j,t];

s.t. perc_min_prod {i in PROD}:
  sum{j in CITTA} x[i,j] >= PercMinProd[i]*(sum{ii in PROD, j in CITTA} x[ii,j]);

s.t. perc_max_prod {i in PROD}:
  sum{j in CITTA} x[i,j] <= PercMaxProd[i]*(sum{ii in PROD, j in CITTA} x[ii,j]);

s.t. perc_min_citta {j in CITTA}:
  sum{i in PROD} x[i,j] >= PercMinCitta[j]*(sum{i in PROD, jj in CITTA} x[i,jj]);

s.t. perc_max_citta {j in CITTA}:
  sum{i in PROD} x[i,j] <= PercMaxCitta[j]*(sum{i in PROD, jj in CITTA} x[i,jj]);

