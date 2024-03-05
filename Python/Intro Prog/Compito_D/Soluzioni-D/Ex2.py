import re

def Ex2(file):
    testo = open(file).read()
    conta_ok = 0
    conta_no = 0
    pattern = r'(\d{1,2})([:.])(\d{1,2})\2(\d{1,2})'
    ris = re.finditer(pattern, testo)
    for m in ris:
        ora = int(m.group(1))
        minuti = int(m.group(3))
        secondi = int(m.group(4))
        print(ora,minuti,secondi)
        if ora > 24 or minuti >= 60 or secondi >= 60:
            conta_no += 1
        else:
            conta_ok += 1
        
    return conta_ok,conta_no
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testo1d.txt'], (3,2))
    counter_test_positivi += tester_fun(Ex2, ['testo2d.txt'], (3,4))
    counter_test_positivi += tester_fun(Ex2, ['testo3d.txt'], (3,4))
    counter_test_positivi += tester_fun(Ex2, ['testo4d.txt'], (4,5))
    counter_test_positivi += tester_fun(Ex2, ['testo5d.txt'], (5,5))

    # test aggiuntivi
  
    counter_test_positivi += tester_fun(Ex2, ['testo6d.txt'], (2,2))
    counter_test_positivi += tester_fun(Ex2, ['testo7d.txt'], (4,3))
    counter_test_positivi += tester_fun(Ex2, ['testo8d.txt'], (4,3))
    counter_test_positivi += tester_fun(Ex2, ['testo9d.txt'], (5,4))
    counter_test_positivi += tester_fun(Ex2, ['testo10d.txt'], (3,6))
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
