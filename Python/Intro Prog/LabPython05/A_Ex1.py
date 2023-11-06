def A_Ex1(s,n):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 4

    counter_test_positivi += tester_fun(A_Ex1, ['scacco matto',3], 'tto')
    counter_test_positivi += tester_fun(A_Ex1, ['scacco',3], 'sca')
    counter_test_positivi += tester_fun(A_Ex1, ['scacco',7], '')
    counter_test_positivi += tester_fun(A_Ex1, ['prova',5], 'prova')

    print('La funzione',A_Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
