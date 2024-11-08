Select * From Giornalista;
Select * From Testata;
SELECT * FROM Firma;

--Query 1
Select Distinct g.codice, g.cittanascita 
From Giornalista g
Join Firma f ON f.codice = g.codice
Where f.anno >= 2000
Order By g.codice;

--Query 2
Select Distinct t.nome 
From Testata t
Join Firma f1 On f1.nome = t.nome
Join Firma f2 On f2.nome = t.nome
Where 	f1.anno = f2.anno and
		f1.mese = (f2.mese-1) and
		f1.codice = f2.codice;

--Query 3
Select g.codice, sum(f.articoli)
From Giornalista g
Join Firma f On f.codice = g.codice
Join Testata t On t.nome = f.nome
Where t.citta = g.cittanascita
Group By g.codice

Union --Serve per inserire gli zeri di tutti quelli che non hanno firmato 

Select g.codice, 0
From Giornalista g 
Where g.codice Not In (	Select g.codice
						From Giornalista g	
						Join Firma f On f.codice = g.codice
						Join Testata t On t.nome = f.nome
						Where t.citta = g.cittanascita);

--Query 4
Select t.nome
From Testata t
Except
Select f.nome
From Firma f
Join Giornalista g On f.codice = g.codice
Where g.orientamento <> 'sinistra';

--Query 5
With maxArticoli as (
	Select f.nome as nome, f.anno as anno, sum(f.articoli) as quanti
	From Firma f
	Join Testata t On t.nome = f.nome
	Where f.codice = t.direttore
	Group By (f.nome, f.anno)
)
Select m.nome, m.anno
From maxArticoli m
Where not Exists (Select * From maxArticoli m2
					Where m.nome = m2.nome and m2.quanti > m.quanti);

