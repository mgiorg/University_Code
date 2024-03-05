def Ex3(nomeFile):
    import pandas as pd
    import numpy as np
    ris = {}
    df=pd.read_csv(nomeFile,header=None)
    m=np.array(df.values)
    righe=m.shape[0]
    colonne=m.shape[1]
    camminoMax=0
    ris=set()
    print(m)
    for i in range(1,righe-1):
        cammino=0
        print(i, end=' ')
        for j in range(0,colonne):
            cammino+=m[i,j]
            print(m[i,j],end='+')
            if j%2==0:    #si sale:
                cammino+=m[i-1,j]
                print(m[i-1,j],end='+')
            else:
                cammino+=m[i+1,j]
                print(m[i+1,j],end='+')
        print('=',cammino)
        if cammino>camminoMax:
            ris={i}
            camminoMax=cammino
        elif cammino==camminoMax:
            ris.add(i)   
    return ris

###############################################################################
#nomeFile='m1.csv'
"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['m1.csv'],{1})
    counter_test_positivi += tester_fun(Ex3, ['m2.csv'],set())
    counter_test_positivi += tester_fun(Ex3, ['m3.csv'],{2})
    counter_test_positivi += tester_fun(Ex3, ['m4.csv'],{1,2})
    counter_test_positivi += tester_fun(Ex3, ['m5.csv'],{1,2})
  

    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex3, ['m6.csv'],{1})
    counter_test_positivi += tester_fun(Ex3, ['m7.csv'],{1})
    counter_test_positivi += tester_fun(Ex3, ['m8.csv'],set())
    counter_test_positivi += tester_fun(Ex3, ['m9.csv'],{2})
    counter_test_positivi += tester_fun(Ex3, ['m10.csv'],{2})

    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
