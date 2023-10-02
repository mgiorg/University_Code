#Compito 1: Scrivere una fattura che chiede:
#	Nome, data del pagamento, totale della fattura (senza iva)
#	Scrivere su un file il dizionario con tutti i dati e poterlo aggiornare di volta in volta
	
	


#	
#Compito 2: Pagamenti dei clienti tipo:
#	Nome, data di pagamento e totale pagamento
#	Scriverlo su un file aggiornabile nel tempo

nome = input("Inserisci il nome del cliente: ")
data = input("Inserisci la data del pagamento formato GG/MM/AAAA: ")
totale = float(input("Inserisci il totale dell'importo senza iva: "))	
	
temp = totale
iva = temp * 0.22
totale = temp + iva
	
dati_pagamenti = {"nome": nome,
				  "data": data,
				  "totale": totale}

filePagamenti = open("pagamenti.txt", "a")
filePagamenti.write(str(dati_pagamenti) + "\n")
filePagamenti.close();

filePagamenti = open("pagamenti.txt", "r")
datiPagamenti = filePagamenti.read()
print(str(datiPagamenti))
filePagamenti.close()