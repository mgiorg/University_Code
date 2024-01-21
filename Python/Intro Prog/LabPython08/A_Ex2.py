def A_Ex2(fileName):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    f = open(fileName, encoding = 'UTF-8')
    linea = f.readLine() #Riga titolo
    temp = []

    while linea != '':
        linea = f.readLine()
        lista = linea.split()

        if int(lista[1]) >= 18:
            temp.append((lista[0], lista[2]))
    f.close()
    
    return temp
            

###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex2, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/esami1.csv"], [('1345','Fisica'),('1346','Analisi'),('1896','Geometria'),('1753','Fisica')])
    counter_test_positivi += tester_fun(A_Ex2, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami2.csv"], [('1346','Analisi')])
    counter_test_positivi += tester_fun(A_Ex2, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami3.csv"], [('1347', 'Analisi'), ('1348', 'Analisi'), ('1347', 'Ricerca Operativa'), ('1349', 'Ricerca Operativa')])
    counter_test_positivi += tester_fun(A_Ex2, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami4.csv"], [('1100', 'Basi di Dati'), ('1012', 'Basi di Dati'), ('1021', 'Analisi')])
    counter_test_positivi += tester_fun(A_Ex2, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami5.csv"], [('1345','Fisica'),('1987','Fondamenti'),('1346','Analisi'),('1896','Geometria')])

    print('La funzione',A_Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)