def Ex2(file):
    import re
    conta = 0
    f=open(file,'r',encoding='UTF-8')
    pattern = r'\b\w*(\w)\1\w*\b\W+\b\w*(\w)\2\w*\b\W+\b\w*(\w)\3\w*\b'
    for riga in f:
        m = re.search(pattern,riga)
        if m:   #senza vincolo
            conta += 1
    return conta   
    
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testoa1.txt'],2)
    counter_test_positivi += tester_fun(Ex2, ['testoa2.txt'],3)
    counter_test_positivi += tester_fun(Ex2, ['testoa3.txt'],4)
    counter_test_positivi += tester_fun(Ex2, ['testoa4.txt'],6)
    counter_test_positivi += tester_fun(Ex2, ['testoa5.txt'],7)

    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex2, ['testoa6.txt'],4) 
    counter_test_positivi += tester_fun(Ex2, ['testoa7.txt'],5) 
    counter_test_positivi += tester_fun(Ex2, ['testoa8.txt'],6) 
    counter_test_positivi += tester_fun(Ex2, ['testoa9.txt'],7) 
    counter_test_positivi += tester_fun(Ex2, ['testoa10.txt'],8)

    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
