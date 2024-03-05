def Ex3(file,n):
    pos = {}
    f = open(file)
    nomi = f.readline().strip().split(',')
    for nome in nomi:
        pos[nome] = 0
    for riga in f:
        tiri = riga.strip().split(',')
        for i in range(len(tiri)):
            tiro = int(tiri[i])
            giocatore = nomi[i]
            fermo=False
            if pos[giocatore] + tiro == n:
                return giocatore
            if pos[giocatore] + tiro < n:
                for altro in nomi:
                    if altro != giocatore and pos[altro] == pos[giocatore] + tiro:
                        fermo=True                  
            if pos[giocatore] + tiro > n:
                fermo=True
            if not fermo:
                pos[giocatore] = pos[giocatore] + tiro
    return 'Nessuno'      

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['mosse1.csv',10],'Paolo')    
    counter_test_positivi += tester_fun(Ex3, ['mosse1.csv',8],'Nessuno')    
    counter_test_positivi += tester_fun(Ex3, ['mosse2.csv',10],'Paolo')    
    counter_test_positivi += tester_fun(Ex3, ['mosse2.csv',9],'Flavio')    
    counter_test_positivi += tester_fun(Ex3, ['mosse2.csv',7],'Paolo')       
    
    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex3, ['mosse3.csv',10],'Giulio')    
    counter_test_positivi += tester_fun(Ex3, ['mosse3.csv',8],'Carlo')    
    counter_test_positivi += tester_fun(Ex3, ['mosse4.csv',10],'Giulio')    
    counter_test_positivi += tester_fun(Ex3, ['mosse4.csv',9],'Flavia')    
    counter_test_positivi += tester_fun(Ex3, ['mosse4.csv',7],'Giulio')       
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
