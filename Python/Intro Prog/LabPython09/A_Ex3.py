def A_Ex3(fileName):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    temp = []
    f = open(fileName, encoding = 'utf-8')

    c = 0
    for elem in f:
        if c != 0:
            s = elem.strip().split(',')
            if int(s[1]) >= 18:
                temp.append(s)
        c = 1
    
    f.close()
    print(temp)

    #temp ha formato [Matricola, Voto, Materia]
    diz = {}
    materie = []


    for elem in temp:
        if elem[2] not in diz:
            diz[elem[2]] = [int(elem[0])]
        else:
            diz[elem[2]].append(int(elem[0]))
        if elem[2] not in materie:
            materie.append(elem[2])

    print(diz)
    print(materie)
    
    for i in range(len(materie)):
        prov = diz.get(materie[i])
        prov.sort()
        diz[materie[i]] = prov

    return diz

#A_Ex3("/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/esami1.csv")


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex3, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/esami1.csv"] , {'Fisica': [1345, 1753], 'Analisi': [1346], 'Geometria': [1896]})
    counter_test_positivi += tester_fun(A_Ex3, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/esami2.csv"] , {'Analisi': [1346]})
    counter_test_positivi += tester_fun(A_Ex3, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/esami3.csv"] , {'Analisi': [1347, 1348], 'Ricerca Operativa': [1347, 1349]})
    counter_test_positivi += tester_fun(A_Ex3, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/esami4.csv"] , {'Basi di Dati': [1012, 1100], 'Analisi': [1021]})
    counter_test_positivi += tester_fun(A_Ex3, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/esami5.csv"] , {'Fisica': [1345], 'Fondamenti': [1987], 'Analisi': [1346], 'Geometria': [1896]})

    print('La funzione',A_Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
