def A_Ex3(fileName):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

    f = open(fileName, encoding = 'UTF-8')
    temp = []
    ins = set()
    c = 0

    for elem in f:
        linea = elem.split(',')
        if c!= 0:
            if int(linea[1]) >= 29:
                temp.append(linea[2].strip())
        c += 1
    f.close()

    s = 0
    for elem in temp:
        if temp.count(elem) >= 2 and elem not in ins:
            ins.add(elem)
    
    return ins

#A_Ex3('/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami1.csv')


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun
    
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex3, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami1.csv"], {'Fisica'})
    counter_test_positivi += tester_fun(A_Ex3, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami2.csv"], set())
    counter_test_positivi += tester_fun(A_Ex3, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami3.csv"], {'Ricerca Operativa','Analisi'})
    counter_test_positivi += tester_fun(A_Ex3, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami4.csv"], {'Basi di Dati'})
    counter_test_positivi += tester_fun(A_Ex3, ["/Users/massimogiordano/Desktop/Programmazione/University_Code/Python/Intro Prog/LabPython08/esami5.csv"], set())

    print('La funzione',A_Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
    