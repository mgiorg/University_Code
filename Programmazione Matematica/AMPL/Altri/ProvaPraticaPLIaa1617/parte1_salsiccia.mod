set Ingredienti;
set CategoriaMagre within Ingredienti;
set CategoriaGrasse within Ingredienti;
set CategoriaSaporite within Ingredienti;

param Costo{Ingredienti}; # Costo per kg
param Proteine{Ingredienti}; # Proteine per kg
param GrassiInsaturi{Ingredienti}; # Grassi insaturi per kg
param GrassiSaturi{Ingredienti}; # Grassi saturi per kg
param Sale{Ingredienti}; # Sale per kg

param PesoTotale; # Peso totale della salsiccia in grammi
param ProteineMin; # Minimo di proteine per 100 g
param ProteineMax; # Massimo di proteine per 100 g
param GrassiInsaturiMin; # Minimo di grassi insaturi per 100 g
param GrassiInsaturiMax; # Massimo di grassi insaturi per 100 g
param GrassiSaturiMin; # Minimo di grassi saturi per 100 g
param GrassiSaturiMax; # Massimo di grassi saturi per 100 g
param SaleMin; # Minimo di sale per 100 g
param SaleMax; # Massimo di sale per 100 g

var Quantita{Ingredienti} >= 0; # Quantità in grammi
var Selezione{Ingredienti} binary; # 1 se l'ingrediente è selezionato, 0 altrimenti
var ProteineSufficienti binary; # 1 se le proteine sono >= 46 g, 0 altrimenti

minimize CostoTotale:
    sum{i in Ingredienti} Costo[i] * (Quantita[i] / 1000); # Conversione da g a kg

# Vincolo sul peso totale
subject to PesoTotaleSalsiccia:
    sum{i in Ingredienti} Quantita[i] = PesoTotale;

# Vincoli sulle forchette nutrizionali (conversione da g a 100 g)
subject to VincoloProteine:
    ProteineMin <= sum{i in Ingredienti} Proteine[i] * (Quantita[i] / 1000) <= ProteineMax;

subject to VincoloGrassiInsaturi:
    GrassiInsaturiMin <= sum{i in Ingredienti} GrassiInsaturi[i] * (Quantita[i] / 1000) <= GrassiInsaturiMax;

subject to VincoloGrassiSaturi:
    GrassiSaturiMin <= sum{i in Ingredienti} GrassiSaturi[i] * (Quantita[i] / 1000) <= GrassiSaturiMax;

subject to VincoloSale:
    SaleMin <= sum{i in Ingredienti} Sale[i] * (Quantita[i] / 1000) <= SaleMax;

# Vincoli su selezione e quantità
subject to CollegamentoSelezioneQuantita {i in Ingredienti}:
    Quantita[i] <= 1000 * Selezione[i]; # Conversione da g a kg

# Vincoli di categoria: almeno un ingrediente selezionato per categoria
subject to MinimoPerCategoriaMagre:
    sum{i in CategoriaMagre} Selezione[i] >= 1;

subject to MinimoPerCategoriaGrasse:
    sum{i in CategoriaGrasse} Selezione[i] >= 1;

subject to MinimoPerCategoriaSaporite:
    sum{i in CategoriaSaporite} Selezione[i] >= 1;

# Vincoli di categoria: al massimo due ingredienti per categoria
subject to MassimoDuePerCategoriaMagre:
    sum{i in CategoriaMagre} Selezione[i] <= 2;

subject to MassimoDuePerCategoriaGrasse:
    sum{i in CategoriaGrasse} Selezione[i] <= 2;

subject to MassimoDuePerCategoriaSaporite:
    sum{i in CategoriaSaporite} Selezione[i] <= 2;

# Esclusione tra lardo e fegato
subject to EsclusioneLardoFegato:
    Selezione["lardo"] + Selezione["fegato"] <= 1;

# Vincolo logico per le proteine
subject to ProteineLogico1:
    sum{i in Ingredienti} Proteine[i] * (Quantita[i] / 1000) - 46 >= -1000 * (1 - ProteineSufficienti);

subject to ProteineLogico2:
    sum{i in Ingredienti} Proteine[i] * (Quantita[i] / 1000) - 46 <= 1000 * ProteineSufficienti;

# Vincoli condizionati alle proteine insufficienti
subject to MagreProteineInsufficienti:
    sum{i in CategoriaMagre} Quantita[i] >= 0.6 * PesoTotale - ProteineSufficienti * 1000;

subject to SaleProteineInsufficienti:
    sum{i in Ingredienti} Sale[i] * (Quantita[i] / 1000) <= 0.5 + ProteineSufficienti * 1000;
