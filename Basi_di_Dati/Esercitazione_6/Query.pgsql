-- CREAZIONE DELLE TABELLE
Create Table corso(
	codice SERIAL PRIMARY KEY,
	tipo VARCHAR(20)
	CHECK(tipo IN ('informatica', 'altro'))
);

Create Table studente(
	codice SERIAL Primary Key,
	eta int not null
	check(eta > 0)
);

Create Table esame(
	id SERIAL primary key,
	codice_studente int not null,
	codice_corso int not null,
	voto int check(voto >= 18 and voto <= 30),
	FOREIGN KEY (codice_studente) REFERENCES studente(codice)
		ON DELETE CASCADE 
		ON UPDATE RESTRICT,	--impedisce gli aggiornamenti del codice studente
	FOREIGN KEY (codice_corso) REFERENCES corso(codice)
		ON DELETE CASCADE	
		ON UPDATE RESTRICT	--impedisce gli aggiornamenti del codice corso
);

Create Table ministero(
	codice_studente int primary key,
	esami_informatica int default 0,
	esami_altro int default 0,
	FOREIGN KEY (codice_studente) references studente(codice)
);

--TRIGGER PER INSERIMENTO ESAMI IN MINISTERO


----QUERY 1