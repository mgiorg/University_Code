set PRODOTTI;  # Prodotti finali
set INGREDIENTI;  # Ingredienti utilizzati
set QUALITA;  # Qualità da soddisfare (es. Dolcezza, Acidità, Umami)

param Prezzo{PRODOTTI};  # Prezzi di vendita al kg
param Costo_base{PRODOTTI};  # Costo base al kg del prodotto
param Quantita_p{PRODOTTI};  # Quantità di prodotto da produrre
param Costo_i{INGREDIENTI};  # Costo al kg degli ingredienti
param Composizione{INGREDIENTI, QUALITA};  # Percentuale di qualità per ingrediente
param MinQualita{QUALITA, PRODOTTI};  # Requisiti minimi di qualità
param MaxQualita{QUALITA, PRODOTTI};  # Requisiti massimi di qualità

var Quantita_i{INGREDIENTI, PRODOTTI} >= 0;  # Quantità di ciascun ingrediente per prodotto

maximize profitto:
    sum {p in PRODOTTI} (Prezzo[p] - Costo_base[p]) * Quantita_p[p]
    - sum {p in PRODOTTI, i in INGREDIENTI} Costo_i[i] * Quantita_i[i, p];

subject to quantita_ingredienti {p in PRODOTTI}:
    sum {i in INGREDIENTI} Quantita_i[i, p] >= Quantita_p[p];

subject to qualita_prodotti_min {q in QUALITA, p in PRODOTTI}:
    MinQualita[q, p] * Quantita_p[p] <= sum {i in INGREDIENTI} Composizione[i,q] * Quantita_i[i, p];

subject to qualita_prodotti_max {q in QUALITA, p in PRODOTTI}:
    sum {i in INGREDIENTI} Composizione[i,q] * Quantita_i[i, p] <= MaxQualita[q, p] * Quantita_p[p];
