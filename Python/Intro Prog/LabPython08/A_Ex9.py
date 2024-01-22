def A_Ex9(fileName,squadra):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    f = open(fileName, encoding = 'utf-8')

    punti = 0
    for elem in f:
        lista = elem.strip().split(',')
        if squadra in lista:
            print(lista)
            index = lista.index(squadra)
            print(index)

            if index == 0:
                if lista[2] > lista[3]:
                    punti+= 3
                elif lista[2] == lista[3]:
                    punti+= 1

            elif index == 1:
                if lista[2] < lista[3]:
                    punti+= 3
                elif lista[2] == lista[3]:
                    punti+= 1
    return punti


#A_Ex9("/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/partite1.csv", 'Chelsea')

###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex9, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/partite1.csv",'Chelsea'] , 3)
    counter_test_positivi += tester_fun(A_Ex9, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/partite1.csv",'Tottenham'] , 1)
    counter_test_positivi += tester_fun(A_Ex9, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/partite2.csv",'Arsenal'] , 4)
    counter_test_positivi += tester_fun(A_Ex9, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/partite2.csv",'Bayern'] , 0)
    counter_test_positivi += tester_fun(A_Ex9, ["/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/LabPython08/partite3.csv",'Bayern'] , 4)

    print('La funzione',A_Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
