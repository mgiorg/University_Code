import pandas as pd

def Ex8(anno,area,file):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex8, [2000,18000,"opere1.xlsx"] , 4)
    counter_test_positivi += tester_fun(Ex8, [1980,5600,"opere1.xlsx"] , 3)
    counter_test_positivi += tester_fun(Ex8, [2000,10000,"opere2.xlsx"] , 8)
    counter_test_positivi += tester_fun(Ex8, [1980,8000,"opere2.xlsx"] , 5)
    counter_test_positivi += tester_fun(Ex8, [1950,20000,"opere2.xlsx"] , 2)
   
    print('La funzione',Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
