def Ex1(s,c1,c2):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['matanto va la gatta al lardo','t','a'],16)
    counter_test_positivi += tester_fun(Ex1, ['tanto va la gatta al lardo che ci lascia','a','o'],16)
    counter_test_positivi += tester_fun(Ex1, ['tanto va la gatta al lardo',' ','a'],20)
    counter_test_positivi += tester_fun(Ex1, ['tanto va la gatta al lardo che ci lascia lo zampino','a',' '],51)
    counter_test_positivi += tester_fun(Ex1, ['tanto va la gatta al lardo','n','o'],25)

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
