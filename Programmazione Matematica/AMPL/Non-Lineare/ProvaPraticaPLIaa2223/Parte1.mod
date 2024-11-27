set ORIGINS; # Set di origini
set DESTINATIONS; # Set di destinazioni
set VEHICLES; # Tipologie di veicoli

param demand {ORIGINS, DESTINATIONS}; # Richiesta giornaliera da origine a destinazione
param distance {ORIGINS, DESTINATIONS}; # Distanza in Km per ciascuna tratta

param capacity {VEHICLES}; # Capacità di ogni veicolo
param fixed_cost {VEHICLES}; # Costo fisso per ogni veicolo
param variable_cost {VEHICLES}; # Costo variabile per 100 Km
param max_vehicles {VEHICLES}; # Numero massimo di veicoli disponibili per ciascuna tipologia
param emissions {VEHICLES}; # Emissioni per 100 Km

param max_emissions := 9000; # Massimo di emissioni consentito
param min_trucks := 130; # Minimo di furgoni veloci richiesti
param penalty_emissions := 1500; # Multa per emissioni sopra il limite
param penalty_trucks := 900; # Multa per uso insufficiente di furgoni veloci
param combined_penalty := 2800; # Multa combinata

var x {VEHICLES, ORIGINS, DESTINATIONS} >= 0, integer; # Numero di veicoli utilizzati
var over_emissions binary; # Se le emissioni superano il limite
var under_trucks binary; # Se i furgoni veloci utilizzati sono insufficienti
var combined_violation binary; # Se entrambe le violazioni si verificano

# Funzione obiettivo: minimizzare i costi totali
minimize total_cost:
    sum {k in VEHICLES, i in ORIGINS, j in DESTINATIONS} (
        fixed_cost[k] * x[k,i,j] +
        variable_cost[k] * x[k,i,j] * distance[i,j] / 100
    )
    + penalty_emissions * over_emissions
    + penalty_trucks * under_trucks
    + combined_penalty * combined_violation;

# Vincoli di soddisfazione della domanda
subject to satisfy_demand {i in ORIGINS, j in DESTINATIONS}:
    sum {k in VEHICLES} capacity[k] * x[k,i,j] >= demand[i,j];

# Vincoli sui limiti di veicoli per tipo
subject to vehicle_limits {k in VEHICLES}:
    sum {i in ORIGINS, j in DESTINATIONS} x[k,i,j] <= max_vehicles[k];

# Vincolo sulle emissioni totali
subject to emissions_limit:
    sum {k in VEHICLES, i in ORIGINS, j in DESTINATIONS}
        emissions[k] * x[k,i,j] * distance[i,j] / 100
    <= max_emissions + over_emissions * max_emissions;

# Vincolo sul numero minimo di furgoni veloci
subject to trucks_limit:
    sum {i in ORIGINS, j in DESTINATIONS} x["furgone veloce",i,j]
    >= min_trucks - under_trucks * min_trucks;

# Vincolo sulla violazione combinata
subject to combined_violation_logic:
    combined_violation >= over_emissions + under_trucks - 1;