def Ex2(fileName,coppia):
    import re
    f=open(fileName,'r',encoding='UTF-8')
    righe = f.readlines()
    f.close()
    ris=0
    pattern=coppia+'[^'+coppia+']*'+coppia
    for riga in righe:
        riga=riga.strip()
        m = re.findall(pattern, riga)
        print(m)
        ris+=len(m)
    return ris   
    
            
###############################################################################




"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testob1.txt','al'],3)
    counter_test_positivi += tester_fun(Ex2, ['testob2.txt','ra'],2)
    counter_test_positivi += tester_fun(Ex2, ['testob3.txt','al'],0)
    counter_test_positivi += tester_fun(Ex2, ['testob4.txt','aa'],1)
    counter_test_positivi += tester_fun(Ex2, ['testob5.txt','aa'],4)


    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex2, ['testob6.txt','al'],1)
    counter_test_positivi += tester_fun(Ex2, ['testob7.txt','so'],2)
    counter_test_positivi += tester_fun(Ex2, ['testob8.txt','ra'],1)
    counter_test_positivi += tester_fun(Ex2, ['testob9.txt','re'],2)
    counter_test_positivi += tester_fun(Ex2, ['testob10.txt','aa'],0)

    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
