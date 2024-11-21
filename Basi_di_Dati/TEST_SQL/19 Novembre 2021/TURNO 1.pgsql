--TURNO 1

SELECT * FROM Giocattolo;
SELECT * FROM Bambino;
SELECT * FROM Richiesta;

--QUERY1
SELECT Distinct b.codice, b.nome
From Bambino b
Join Richiesta r On r.codiceb = b.codice
Where b.citta <> 'Milano' And r.preferenza >= 4;

--QUERY2
Select Distinct r1.codiceb
From Richiesta r1, Richiesta r2, Giocattolo g1, Giocattolo g2
Where r1.codiceg = g1.codice And r2.codiceg = g2.codice
        And r1.preferenza = r2.preferenza And g1.categoria <> g2.categoria
        And r1.codiceb = r2.codiceb;

--Query3
Select b.codice, b.citta, count(r.preferenza)
From Bambino b
Join Richiesta r On r.codiceb = b.codice
Where r.preferenza = 1
GROUP BY b.codice, b.citta
Union
Select r.codiceb, b.citta, 0
From Bambino b Join Richiesta r On r.codiceb = b.codice
Where (b.codice) not in (select codiceb From Richiesta Where preferenza = 1);

--Query4
Select r.codiceb, r.codiceg, max(r.preferenza)
From Richiesta r
Group By r.codiceb, r.codiceg
Union
Select b.codice, g.codice, 0
From Bambino b, Giocattolo g
Where (b.codice, g.codice) not in (Select codiceb, codiceg From Richiesta);

--Query5
Select codiceg, avg(preferenza) From richiesta
Where codiceg in (  Select codice From Giocattolo
                    Except
                    Select r.codiceg From Richiesta r
                    Join Bambino b On r.codiceb = b.codice
                    Where b.citta = 'Firenze')
Group By codiceg
Union
Select codice, null From Giocattolo
Where codice not in (select codiceg From richiesta);