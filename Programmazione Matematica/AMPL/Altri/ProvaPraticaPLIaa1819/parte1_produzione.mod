set Prodotti ordered;
set Macchine ordered;

param p{Prodotti}; # Prezzo per unità del prodotto
param F{Prodotti}; # Costo fisso per l'attivazione del prodotto
param u{Prodotti}; # Upper bound sulla produzione (in grammi)
param Minuti{Macchine, Prodotti}; # Minuti richiesti per lavorare 1 kg di ogni prodotto su ogni macchina
param MinutiDisponibili{Macchine}; # Minuti totali disponibili per ogni macchina

param DomandaBaseMin;
param DomandaPremiumMin;

set ProdottiBase within Prodotti;
set ProdottiPremium within Prodotti;

var q{i in Prodotti} >= 0, <= u[i]; # Quantità prodotta di ciascun prodotto
var z{i in Prodotti} binary; # 1 se il prodotto è attivato, 0 altrimenti

maximize Ricavo:
    sum{i in Prodotti} (p[i] * q[i] - F[i] * z[i]);

# Vincolo di attivazione del prodotto
subject to AttivazioneProdotto {i in Prodotti}:
    q[i] <= u[i] * z[i];

subject to CapacitaMacchine {m in Macchine}:
    sum{i in Prodotti} Minuti[m, i] * (q[i] / 1000) <= MinutiDisponibili[m];

subject to DomandaBase:
    sum{i in ProdottiBase} q[i] >= DomandaBaseMin;

subject to DomandaPremium:
    sum{i in ProdottiPremium} q[i] >= DomandaPremiumMin;

# Vincoli condizionali
var Vincolo1 binary; # Indica se sono rispettati i vincoli sul 25% e l'80%
var Vincolo2 binary; # Indica se sono rispettati i vincoli alternativi

subject to VincoliLogici:
    Vincolo1 + Vincolo2 <= 1;

subject to Vincolo25Percento:
   q['P1'] >= 0.25 * sum{i in Prodotti} q[i] - Vincolo1 * 100000;

subject to Vincolo80Percento:
    sum{i in ProdottiPremium} q[i] >= 0.8 * sum{i in ProdottiBase} q[i] - Vincolo1 * 100000;

subject to VincoloP4Max:
    q["P4"] <= 1000 + Vincolo2 * 100000;

subject to VincoloP3Min:
    q["P3"] >= 5000 - Vincolo2 * 100000;
