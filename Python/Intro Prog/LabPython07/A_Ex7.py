def A_Ex7(l):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 3

    counter_test_positivi += tester_fun(A_Ex7, [[['italiano',6], ['geografia',10], ['matematica',6],['storia',8], ['matematica', 10], ['storia', 8], ['geografia', 7]]] , ('geografia',10))
    counter_test_positivi += tester_fun(A_Ex7, [[['italiano',7], ['storia',6]]], ('italiano',7))
    counter_test_positivi += tester_fun(A_Ex7, [[['storia',4],['storia',6],['matematica',7]]], ('storia',6))



    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
