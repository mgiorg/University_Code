def funzione_4(nomefile):
    diz = {}

    f = open(nomefile, 'r')
    for riga in f:
        parola = ''
        riga = riga.strip()

        for c in riga:
            if c != 'a' and c != 'e' and c != 'i' and c != 'o' and c != 'u' and c != 'A' and c != 'E' and c != 'I' and c != 'O' and c != 'U':
                parola+= c
        diz[parola] = len(parola)

    f.close()
    return diz
