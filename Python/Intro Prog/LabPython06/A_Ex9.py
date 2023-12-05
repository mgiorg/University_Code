def A_Ex9(l):
     """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex9, [['casa', 'albero', 'bello']] , {'a','l'})
    counter_test_positivi += tester_fun(A_Ex9, [['ciao', 'ciao']] , set())
    counter_test_positivi += tester_fun(A_Ex9, [['aa','aa','hghjklhl']] , {'a','h','l'})
    counter_test_positivi += tester_fun(A_Ex9, [[]] , set())
    counter_test_positivi += tester_fun(A_Ex9, [['cogito', 'ergo', 'sum']] , {'o'})


    print('La funzione',A_Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
