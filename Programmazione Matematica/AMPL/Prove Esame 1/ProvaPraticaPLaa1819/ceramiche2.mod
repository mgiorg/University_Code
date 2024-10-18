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

var x{PROD,CITTA,MP} >= 0;

s.t. bound {i in PROD, j in CITTA}:
  l[i,j] <= sum{t in MP} x[i,j,t] <= u[i,j];

maximize ricavo:
  sum{i in PROD, j in CITTA, t in MP} Prez[i]*x[i,j,t];

s.t. risorsa_reparti {j in CITTA, k in REP}:
  sum{i in PROD, t in MP} ConsMinRep[i,k]*x[i,j,t] <= 60*MaxOreRep[j,k];

s.t. risorsa_mp {t in MP}:
  sum{i in PROD, j in CITTA} 2*ConsMP[i,t]*x[i,j,t] <= sum{j in CITTA} DispMP[j,t];

s.t. perc_min_prod {i in PROD}:
  sum{j in CITTA, t in MP} x[i,j,t] >= PercMinProd[i]*(sum{ii in PROD, j in CITTA, t in MP} x[ii,j,t]);

s.t. perc_max_prod {i in PROD}:
  sum{j in CITTA, t in MP} x[i,j,t] <= PercMaxProd[i]*(sum{ii in PROD, j in CITTA, t in MP} x[ii,j,t]);

s.t. perc_min_citta {j in CITTA}:
  sum{i in PROD, t in MP} x[i,j,t] >= PercMinCitta[j]*(sum{i in PROD, jj in CITTA, t in MP} x[i,jj,t]);

s.t. perc_max_citta {j in CITTA}:
  sum{i in PROD, t in MP} x[i,j,t] <= PercMaxCitta[j]*(sum{i in PROD, jj in CITTA, t in MP} x[i,jj,t]);

