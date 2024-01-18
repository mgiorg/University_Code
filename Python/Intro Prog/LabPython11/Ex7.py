import pandas as pd

def Ex7(anno,file):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex7, [2000,"artisti1.xlsx"] , 11)
    counter_test_positivi += tester_fun(Ex7, [1980,"artisti1.xlsx"] , 7)
    counter_test_positivi += tester_fun(Ex7, [2000,"artisti2.xlsx"] , 16)
    counter_test_positivi += tester_fun(Ex7, [1980,"artisti2.xlsx"] , 10)
    counter_test_positivi += tester_fun(Ex7, [1950,"artisti2.xlsx"] , 4)
   
    print('La funzione',Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
