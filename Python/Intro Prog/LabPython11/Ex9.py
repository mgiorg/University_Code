import pandas as pd

def Ex9(file1,file2):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 4

    counter_test_positivi += tester_fun(Ex9, ["artisti1.xlsx","opere1.xlsx"] , 4)
    counter_test_positivi += tester_fun(Ex9, ["artisti1.xlsx","opere2.xlsx"] , 4)
    counter_test_positivi += tester_fun(Ex9, ["artisti2.xlsx","opere1.xlsx"] , 3)
    counter_test_positivi += tester_fun(Ex9, ["artisti2.xlsx","opere2.xlsx"] , 3)
   
    print('La funzione',Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
