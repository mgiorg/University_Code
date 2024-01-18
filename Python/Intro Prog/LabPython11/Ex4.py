def Ex4(m):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    
###############################################################################
import numpy as np
if __name__ == '__main__':
    from tester import tester_fun   

    counter_test_positivi = 0
    total_tests = 3

    counter_test_positivi += tester_fun(Ex4, [np.array([[1,1,1],[1,0,0],[1,1,1]])], (2,0))
    counter_test_positivi += tester_fun(Ex4, [np.array([[3,1,3],[2,1,2],[2,1,2]])], (0,3))
    counter_test_positivi += tester_fun(Ex4, [np.array([[1,2,3],[1,2,3],[1,2,3]])], (0,0))


    print('La funzione',Ex4.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
