def Ex2(file):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    import re
    count = 0
    f = open(file, 'r', encoding='utf-8')

    pattern = r'\b\w*(\w)\1\w*\b\W+\b\w*(\w)\2\w*\b\W+\b\w*(\w)\3\w*\b'

    for elem in f:
        m = re.search(pattern, elem)

        if m:
            count += 1
    f.close()

    #print(temp)
    return count
        

#Ex2('/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_A/testoa3.txt')

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_A/testoa1.txt'],2)
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_A/testoa2.txt'],3)
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_A/testoa3.txt'],4)
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_A/testoa4.txt'],6)
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_A/testoa5.txt'],7)

    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
