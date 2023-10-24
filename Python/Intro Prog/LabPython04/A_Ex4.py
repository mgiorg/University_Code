def A_Ex4(n1,n2):

    if n1 == 0 or n2 == 0:
        return 0
    if abs(n1) < abs(n2):
        max = n2
        min = n1
    else:
        max = n1
        min = n2
    somma = 0

    for i in range(abs(min)):
        somma = somma + abs(max)

    if (n1 < 0 and n2 < 0) or (n1 > 0 and n2 > 0):
        return somma
    else:
        return (-somma)
        
            


###############################################################################



if __name__ == '__main__':
    from tester import tester_fun


    counter_test_positivi = 0
    total_tests = 5
    
    counter_test_positivi += tester_fun(A_Ex4, [5,2], 10)
    counter_test_positivi += tester_fun(A_Ex4, [-3,4], -12)
    counter_test_positivi += tester_fun(A_Ex4, [20,5], 100)
    counter_test_positivi += tester_fun(A_Ex4, [-6,-50], 300)
    counter_test_positivi += tester_fun(A_Ex4, [2,0], 0)

    print('La funzione',A_Ex4.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
