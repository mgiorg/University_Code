def A_Ex4(filename,anno):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    temp = []

    f = open(filename, encoding = 'utf-8')
    for elem in f:
        linea = elem.strip().split(',')
        temp.append((linea)) #creato l'array d'appoggio
    f.close()
    print(temp)

    index = temp[0].index(str(anno)) #indice dell'anno su cui contare le vendite

    c = 0
    max = 0
    for elem in temp:
        if c != 0:
            if int(elem[index]) >= max:
                max = int(elem[index]) #trovo il massimo
        c = 1
    print(index)
    print(max)

    c = 0
    name = []
    for elem in temp:
        if c != 0:
            if int(elem[index]) == max:
                name.append(elem[0])
                print(elem[0])
        c = 1
    name.sort()

    return name[0]
    



#A_Ex4('/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/Vendite1.csv', 2010)
###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex4, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/Vendite1.csv',2012] , 'Giubbotto')
    counter_test_positivi += tester_fun(A_Ex4, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/Vendite2.csv',2012] , 'Maglione')
    counter_test_positivi += tester_fun(A_Ex4, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/Vendite2.csv',2013] , 'Zaino')
    counter_test_positivi += tester_fun(A_Ex4, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/Vendite3.csv',2011] , 'Giubbotto')
    counter_test_positivi += tester_fun(A_Ex4, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/Vendite3.csv',2010] , 'Cellulare')
    
    print('La funzione',A_Ex4.__name__,'ha superato',counter_test_positivi,'test su',total_tests)