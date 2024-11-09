SELECT * FROM prodotto;
SELECT * FROM tipocomponente;
SELECT * FROM contenuto;

--Query1
Select t.codice, t.costo 
From tipocomponente t
Join contenuto c On c.codicet = t.codice
Join prodotto p On c.codicep = p.codice
Where p.categoria in ('Sport', 'Edilizia');

--Query2
Select c.codicep
From contenuto c
Join tipocomponente t On c.codicet = t.codice
Where t.materiale = 'Ferro'
Except
Select c.codicep
From contenuto c
Join tipocomponente t On c.codicet = t.codice
Where t.materiale = 'Plastica';

--Query3
Select distinct p.codice, t.materiale, sum(c.quantita)
From contenuto c
Join prodotto p On c.codicep = p.codice
Join tipocomponente t On c.codicet = t.codice
Group by (p.codice, t.materiale)
union
select distinct p.codice, t.materiale,0
from prodotto p, tipocomponente t
where (p.codice, t.materiale) not in 
        (select p.codice, t.materiale from tipocomponente t
                                    Join contenuto c on t.codice = c.codicet);

--Query4
Select t.codice, t.costo, count(c.codicet)
From contenuto c
Join tipocomponente t On c.codicet = t.codice
Where c.quantita >= 3
Group By t.codice
Union
Select t.codice, t.costo, 0
From tipocomponente t 
Join contenuto c On c.codicet = t.codice
Where (t.codice, t.costo) not in (select t.codice, t.costo from contenuto c
                                Join tipocomponente t On c.codicet = t.codice
                                Where c.quantita >= 3);

--Query5
Select codice from tipocomponente
except
Select t.codice from tipocomponente t
Join contenuto c on c.codicet = t.codice
Join prodotto p on p.codice = c.codicep
Where p.categoria is not null;