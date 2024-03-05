def Ex1(l):
    if len(l) == 0:
        return -1
    coppie = 0
    maggiori=set()
    for i in range(len(l)):       
        if len(l[i])==0 or i in maggiori or len(l[i])+i>len(l)-1:
            continue
        if len(l[i]) == len(l[i+len(l[i])]):
            coppie += 1
            maggiori.add(i+len(l[i]))
    return coppie
    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione


    counter_test_positivi += tester_fun(Ex1, [ ['io','mio','tu','mio','il','mio']],1)
    counter_test_positivi += tester_fun(Ex1, [ []],-1)
    counter_test_positivi += tester_fun(Ex1, [ ['a','b','c','d','e','f']],3)
    counter_test_positivi += tester_fun(Ex1, [ ['io','mio','tuo','io','il','i']],0)
    counter_test_positivi += tester_fun(Ex1, [ ['io','a','il']],1)


    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex1, [ ['','','mio','il','mio']],0)
    counter_test_positivi += tester_fun(Ex1, [ ['a']],0)
    counter_test_positivi += tester_fun(Ex1, [ ['a','a']],1)
    counter_test_positivi += tester_fun(Ex1, [ ['io','a','i']],1)
    counter_test_positivi += tester_fun(Ex1, [ ['i','a','il']],1)
    
    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
