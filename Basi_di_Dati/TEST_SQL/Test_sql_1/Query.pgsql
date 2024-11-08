SELECT * FROM citta;
SELECT * FROM centralina;
SELECT * FROM rilevazione;

--QUERY 1
SELECT r.codice, r.giorno, r.valore FROM Rilevazione r
JOIN Centralina c ON (r.codice = c.codice)
JOIN Citta ci ON ci.id = c.citta 
WHERE r.valore > 100 and c.tipo <> 1 and ci.nome <> 'Milano';

--QUERY 2
Select c.codice, ci.regione, avg(r.valore) 
FROM Centralina c
Join Citta ci ON  c.citta = ci.id
Join Rilevazione r ON r.codice = c.codice
GROUP BY c.codice, ci.regione
ORDER BY c.codice;

--QUERY 3
SELECT r1.codice FROM Rilevazione r1
JOIN Rilevazione r2 ON r2.codice = r1.codice
WHERE r1.giorno = (r2.giorno-1) AND r1.codice = r2.codice
GROUP BY r1.codice
HAVING count(r1.codice) > 1;

--QUERY 4
SELECT c.codice FROM centralina c
WHERE c.codice IN (SELECT r.codice FROM rilevazione r)
EXCEPT
SELECT r.codice FROM rilevazione r
WHERE r.giorno > 90
ORDER BY codice;

--Media Livello Inquinamento Nazionale
SELECT avg(r.valore) as LivelloInquinamentoNazionale FROM rilevazione r;

--QUERY 5
SELECT ci.regione FROM Citta ci
JOIN Centralina c ON c.citta = ci.id
JOIN Rilevazione r ON r.codice = c.codice
GROUP BY ci.regione
HAVING avg(r.valore) < (SELECT avg(r.valore) FROM Rilevazione r);





