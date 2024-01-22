def A_Ex2(file):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

    diz = {}

    f = open(file, encoding = 'utf-8')
    list = []

    for riga in f:
        list.append(riga.strip().split(' '))

    f.close()

    riga = 1
    for elem in list:
        for i in elem:
            if i not in diz:
                diz[i] = {riga}
            else:
                diz[i].add(riga)
        
        riga += 1

    return diz



#A_Ex2('/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/testo1.txt')
     
###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/testo1.txt'] , {'tanto': {1, 2}, 'va': {1, 2}, 'la': {1, 2}, 'gatta': {1, 2}, 'al': {1}, 'lardo': {1}, 'che': {1}, 'ci': {1}, 'lascia': {1, 3}, 'lo': {1, 3}, 'zampino': {1, 3}})
    counter_test_positivi += tester_fun(A_Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/testo2.txt'] , {'tanto': {1, 2}, 'va': {1, 2}, 'la': {1, 2}, 'gatta': {1, 2, 4}, 'al': {1}, 'lardo': {1}, 'che': {1}, 'ci': {1}, 'lascia': {1, 3}, 'lo': {1, 3}, 'zampino': {1, 3, 4}})
    counter_test_positivi += tester_fun(A_Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/testo3.txt'] , {'tanto': {1, 2}, 'va': {1, 2}, 'la': {1, 2}, 'gatta': {1, 2, 4}, 'ci': {1}, 'lascia': {1, 3}, 'lo': {1, 3}, 'zampino': {1, 3, 4}})
    counter_test_positivi += tester_fun(A_Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/testo4.txt'] , {'tanto': {1, 2}, 'va': {1, 2}, 'la': {1, 2}, 'gatta': {1, 2, 4}, 'ci': {1}, 'lascia': {1, 3}, 'lo': {1, 3}, 'zampino': {1}, 'zampone': {3}, 'zampina': {4}})
    counter_test_positivi += tester_fun(A_Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython09/testo5.txt'] , {'tanto': {1, 2}, 'va': {1, 2}, 'la': {1, 2}, 'gatta': {1, 2, 4}, 'ci': {1}, 'lascia': {1, 3}, 'lo': {1, 3}, 'zampino': {1}, 'zampone': {3, 6}, 'zampina': {4}, 'palla': {5}})

    print('La funzione',A_Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
