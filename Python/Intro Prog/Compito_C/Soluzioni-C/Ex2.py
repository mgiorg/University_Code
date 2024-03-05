import re

def Ex2(file):
    testo = open(file).read()
    conta_ok = 0
    conta_no = 0
    pattern = r'(\d{1,2})([/-])(\d{1,2})\2(\d\d)?\d\d\b'
    ris = re.finditer(pattern, testo)
    for m in ris:
        giorno = int(m.group(1))
        mese = int(m.group(3))
        if giorno <= 0 or giorno > 31 or mese <= 0 or mese >= 13:
            conta_no += 1
        elif (mese == 2 and giorno >= 29) or (mese in [4,6,9,11] and giorno >= 31):
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

    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo1c.txt'], (2,3))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo2c.txt'], (2,4))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo3c.txt'], (2,4))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo4c.txt'], (3,5))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo5c.txt'], (4,5))

    # test aggiuntivi
  
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo6c.txt'], (2,3))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo7c.txt'], (2,5))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo8c.txt'], (3,3))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo9c.txt'], (3,6))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/Soluzioni-C/testo10c.txt'], (4,5))
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
