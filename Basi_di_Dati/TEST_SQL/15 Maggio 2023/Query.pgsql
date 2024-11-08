Select * From Giornalista;
Select * From Testata;
SELECT * FROM Firma;

--Query 1
Select g.codice, g.sesso
From Giornalista g
Join Firma f On f.codice = g.codice
Join Testata t On f.nome = t.nome
Where t.orientamento = g.orientamento
Group By (g.codice, g.sesso)
Having sum(f.articoli) > 1;

--Query 2
Select g.codice, t.direttore, sum(f.articoli)
From Firma f
Join Giornalista g On g.codice = f.codice
Join Testata t On t.nome = f.nome
Group By (g.codice, t.direttore)
Order by g.codice;

--Query 3
With Polarizzato as (
	Select direttore from Testata
	Except
	Select t.direttore From Testata t
	Join Giornalista g On t.direttore = g.codice
	Where t.orientamento <> g.orientamento
)
Select * from Polarizzato;

--Query 4
Select g.orientamento, count(distinct g.codice) FROM giornalista g
Join Firma f On f.codice = g.codice
Join Testata t On t.nome = f.nome
Where g.sesso = 'F' and g.orientamento = t.orientamento and f.articoli > 1
Group by g.orientamento, g.codice
Union
Select distinct t1.orientamento, 0
From (select orientamento from Testata union select orientamento from Giornalista) t1
Where t1.orientamento not in (Select g.orientamento FROM giornalista g
Join Firma f On f.codice = g.codice
Join Testata t On t.nome = f.nome
Where g.sesso = 'F' and g.orientamento = t.orientamento and f.articoli > 1);

--Query 5
Select g.codice, g.sesso, min(f.anno) as minimo, max(f.anno) as massimo,
	   max(f.anno) - min(f.anno) + 1 - count(distinct f.anno)
From Giornalista g
Join Firma f On f.codice = g.codice
Group by g.codice, g.sesso

Union

select g.codice, g.sesso, null, null, null
From Giornalista g
Where g.codice not in (select f.codice from firma f);