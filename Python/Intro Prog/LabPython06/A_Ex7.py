def A_Ex7(l):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex7, [['amaca','amaranto','rosso']], ('a','a','o'))
    counter_test_positivi += tester_fun(A_Ex7, [['osso','assolato','alto']], ('o','a','a'))
    counter_test_positivi += tester_fun(A_Ex7, [['stringa','a','bbbbcccc','dado']], ('a','a','b','d'))
    counter_test_positivi += tester_fun(A_Ex7, [['fosso','dosso','rosso','fosso']], ('o', 'o', 'o', 'o'))
    counter_test_positivi += tester_fun(A_Ex7, [['ciao mamma','ciao ']], ('a', ' '))

    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

