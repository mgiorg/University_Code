def Ex2(file):
    import re
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testoa1.txt'],2)
    counter_test_positivi += tester_fun(Ex2, ['testoa2.txt'],3)
    counter_test_positivi += tester_fun(Ex2, ['testoa3.txt'],4)
    counter_test_positivi += tester_fun(Ex2, ['testoa4.txt'],6)
    counter_test_positivi += tester_fun(Ex2, ['testoa5.txt'],7)

    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
