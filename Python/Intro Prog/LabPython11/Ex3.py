def Ex3(m):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

   
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re
    import numpy as np

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex3, [np.array([[1,0],[1,1]])], 'Principale')
    counter_test_positivi += tester_fun(Ex3, [np.array([[0,1],[1,1]])], 'Secondaria')
    counter_test_positivi += tester_fun(Ex3, [np.array([[1,1],[1,1]])], 'Uguali')
    counter_test_positivi += tester_fun(Ex3, [np.array([[1,1,1],[1,1,1],[1,1,1]])], 'Uguali')
    counter_test_positivi += tester_fun(Ex3, [np.array([])], 'Uguali')
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
