SELECT * FROM Giornalista;
SELECT * FROM Testata;
SELECT * FROM Firma;

----------QUERY 1
SELECT DISTINCT g.codice, g.cittanascita 
FROM Giornalista g
JOIN Firma f ON f.codice = g.codice
JOIN Testata t ON t.nome = f.nome
WHERE g.orientamento <> t.orientamento;

----------QUERY 2
SELECT g.codice
FROM Giornalista g
JOIN Testata t ON t.direttore = g.codice
EXCEPT (SELECT t.direttore FROM Testata t
		JOIN Firma f ON f.codice = t.direttore
		WHERE f.nome = t.nome);

----------QUERY 3
SELECT DISTINCT g.codice, t.nome, SUM(f.articoli) as somma
FROM Giornalista g, Testata t, Firma f
WHERE g.codice = f.codice AND
	  f.nome = t.nome
GROUP BY g.codice, t.nome
HAVING SUM(f.articoli) < 10;

----------QUERY 4
SELECT t.nome FROM Testata t
JOIN Firma f ON f.nome = t.nome
JOIN Giornalista g ON g.codice = f.codice
EXCEPT (SELECT t.nome FROM Testata t
		JOIN Firma f ON f.nome = t.nome
		JOIN Giornalista g ON g.codice = f.codice
		WHERE g.orientamento <> t.orientamento);

----------QUERY 5
WITH ScoreCTE AS (
    SELECT 
        g.codice AS codice_giornalista,
        g.orientamento AS orientamento_giornalista,
        t.orientamento AS orientamento_testata,
        SUM(f.articoli) AS score
    FROM giornalista g
    JOIN firma f ON g.codice = f.codice
    JOIN testata t ON f.nome = t.nome
    GROUP BY g.codice, g.orientamento, t.orientamento
),

MaxScoreCTE AS (
    SELECT 
        codice_giornalista,
        orientamento_giornalista,
        orientamento_testata,
        score,
        RANK() OVER (PARTITION BY codice_giornalista ORDER BY score DESC) AS rank
    FROM ScoreCTE
)

SELECT 
    codice_giornalista, orientamento_giornalista, orientamento_testata
FROM MaxScoreCTE
WHERE rank = 1;

