def Ex3(file1,n):


###############################################################################
"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',3],2)
    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',4],1) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',2],3) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',1],2) 
    counter_test_positivi += tester_fun(Ex3, ['esempio2c.txt',5],2) 

    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
