def Ex5(m):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    
###############################################################################
import numpy as np
if __name__ == '__main__':
    from tester import tester_fun   

    counter_test_positivi = 0
    total_tests = 3
    counter_test_positivi += tester_fun(Ex5, [np.array([[1,2,3],[1,0,0],[1,1,1]])], 1)
    counter_test_positivi += tester_fun(Ex5, [np.array([[1,2,2],[1,0,0],[1,1,1]])], 0)
    counter_test_positivi += tester_fun(Ex5, [np.array([[1,2,3],[1,2,3],[1,2,3]])], 3)
    
    print('La funzione',Ex5.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
