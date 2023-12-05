def A_Ex5(l):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""    
    counter_test_positivi = 0
    total_tests = 10

    counter_test_positivi += tester_fun(A_Ex5, [[10,1,11,31,251]] , [10,1,11,31,251,10,20,220,10,200,190])
    counter_test_positivi += tester_fun(A_Ex5, [[]] , [])
    counter_test_positivi += tester_fun(A_Ex5, [[2,7,3]] , [2,7,3,5,2])
    counter_test_positivi += tester_fun(A_Ex5, [[200,501,300]] , [200,501,300,301,1])
    counter_test_positivi += tester_fun(A_Ex5, [[3,2,0]] , [3,2,0])

    counter_test_positivi += tester_fun(A_Ex5, [[1,2,3,4,5]] , [1, 2, 3, 4, 5, 1, 1, 1, 1])
    counter_test_positivi += tester_fun(A_Ex5, [[1,2,3,4,5,5,4,3,2,1]] , [1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 1, 1, 1, 1])
    counter_test_positivi += tester_fun(A_Ex5, [[1,1,3,3,9,9]] , [1, 1, 3, 3, 9, 9, 2, 6, 4])
    counter_test_positivi += tester_fun(A_Ex5, [[1]] , [1])
    counter_test_positivi += tester_fun(A_Ex5, [[0,2,0,3,0,5]] , [0, 2, 0, 3, 0, 5, 2, 3, 5, 1, 2, 1])


    print('La funzione',A_Ex5.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
