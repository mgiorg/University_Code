def Ex2(file):
    import re
    f=open(file,'r',encoding='UTF-8')
    parole = f.read().strip().split()
    f.close()
    ris=set()
    lMax=0
    pattern = '[^a]*a(.*)a'
    for parola in parole:
        m = re.search(pattern, parola)
        if m:
            if len(m.group(1))>lMax:
                lMax=len(m.group(1))
                ris={m.group(0)}
            if len(m.group(1))>0 and len(m.group(1))==lMax:
                ris.add(m.group(0))
    return ris   
    
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testoa1.txt'],{'cassata','sassata'})    
    counter_test_positivi += tester_fun(Ex2, ['testoa2.txt'],set())   
    counter_test_positivi += tester_fun(Ex2, ['testoa3.txt'],{'cassa','massa'})   
    counter_test_positivi += tester_fun(Ex2, ['testoa4.txt'],{'aaa','aba','aca'}) 
    counter_test_positivi += tester_fun(Ex2, ['testoa5.txt'],{'aaaa'}) 
    
    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex2, ['testoa6.txt'],set())    
    counter_test_positivi += tester_fun(Ex2, ['testoa7.txt'],set())   
    counter_test_positivi += tester_fun(Ex2, ['testoa8.txt'],{'casa'})   
    counter_test_positivi += tester_fun(Ex2, ['testoa9.txt'],{'marea'}) 
    counter_test_positivi += tester_fun(Ex2, ['testoa10.txt'],{'aaa'}) 
     
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
