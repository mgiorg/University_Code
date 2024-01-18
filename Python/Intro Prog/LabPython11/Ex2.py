def Ex2(file):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
   
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex2, ["file2_1.csv"] , ([108,17,122],[90,25,30,102]))
    counter_test_positivi += tester_fun(Ex2, ["file2_2.csv"] , ([],[]))
    counter_test_positivi += tester_fun(Ex2, ["file2_3.csv"] , ([10],[2,3,0,5]))
    counter_test_positivi += tester_fun(Ex2, ["file2_4.csv"] , ([104,10],[1,15,98]))
    counter_test_positivi += tester_fun(Ex2, ["file2_5.csv"] , ([105,10,3,2],[5,15,100]))
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
