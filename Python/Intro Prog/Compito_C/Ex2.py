def Ex2(file):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
    corrette = 0
    sbagliate = 0
    lista = []
    data = []
    with open(file, 'r', encoding = 'utf-8') as f:
        r = f.read()
        riga = r.strip().split(' ')
        for i in riga:
            if ord(i[0]) >= ord('0') and ord(i[1]) <= ord('9'):
                lista.append(i)
        
        for i in lista:
            d = i.split('/')
            if len(d) != 3:
                for j in d:
                    data = j.split('-')
                    print(data)
            else:
                data = d

            flag = 1
            
            if len(data) == 3:
                for i in data:
                    if not i.isdigit():
                        flag = 0
            if flag:
                giorno = int(data[0])
                mese = int(data[1])
                anno = int(data[2])

                if flag:
                    if int(data[1]) >= 1 and int(data[1]) <= 12:
                        if int(data[0]) >= 1 and int(data[0]) <= 31:

            else:
                sbagilate += 1

            

            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/testo1c.txt'], (2,3))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/testo2c.txt'], (2,4))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/testo3c.txt'], (2,4))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/testo4c.txt'], (3,5))
    counter_test_positivi += tester_fun(Ex2, ['/home/massimogiordano/Desktop/Repository/University_Code/Python/Intro Prog/Compito_C/testo5c.txt'], (4,5))

    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
