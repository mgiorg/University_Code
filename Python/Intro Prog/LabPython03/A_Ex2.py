def A_Ex2(s1,s2):
    if s1 == '' or s2 == '':
       return 0
   
    else:
        max = ''
        min = ''
        stringa = ''
        x = 0
        if len(s1) >= len(s2):
            max = s1
            min = s2
        else:
            max = s2
            min = s1
        
        for i in range(len(max)):
            c1 = max.count(max[i])
            c2 = min.count(max[i])
                
            if c1 == c2 and max[i] not in stringa:
                x += 1
            
            stringa = stringa + max[i]
    
    return x

      


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun


    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex2, ['caso palese','casa blue'],4)
    counter_test_positivi += tester_fun(A_Ex2, ['caso palese','casata blue'],3)
    counter_test_positivi += tester_fun(A_Ex2, ['caso palese','casacca blue sole'],3)
    counter_test_positivi += tester_fun(A_Ex2, ['','casa blue'],0)
    counter_test_positivi += tester_fun(A_Ex2, ['',''],0)

    print('La funzione',A_Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
