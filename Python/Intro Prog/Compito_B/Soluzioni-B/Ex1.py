def Ex1(l):
    if len(l) == 0:
        return -1
    coppie = 0
    maggiori=set()
    for i in range(len(l)):
        k=l[i].count(l[i][0])
        if k==1 or i in maggiori or k+i>len(l)-1:
            continue
        if k == l[i+k].count(l[i+k][0]):
            coppie += 1
            maggiori.add(i+k)
    return coppie
    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, [ ['oro','mio','alla','mio','ara','mio']],1)
    counter_test_positivi += tester_fun(Ex1, [ []],-1)
    counter_test_positivi += tester_fun(Ex1, [ ['allegra brigata','b','c','f','elemento soave','e','f']],1)
    counter_test_positivi += tester_fun(Ex1, [ ['ioi','mioo','tuu','ioo','il','i']],0)
    counter_test_positivi += tester_fun(Ex1, [ ['oo','a','ii']],1)

    # test aggiuntivi
    counter_test_positivi += tester_fun(Ex1, [ ['a','a','mio','il','mio']],0)
    counter_test_positivi += tester_fun(Ex1, [ ['a']],0)
    counter_test_positivi += tester_fun(Ex1, [ ['aa','ccc','bb','g','aaa']],2)   
    counter_test_positivi += tester_fun(Ex1, [ ['aa','bb','bb']],1)
    counter_test_positivi += tester_fun(Ex1, [ ['a','aa','c','bb']],1)

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
