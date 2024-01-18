def Ex3(file):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['prezzi1.csv'],{'giacca': 'marzo', 'pantalone': 'febbraio', 'camicia': 'nessun rincaro'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi2.csv'],{'giacca': 'marzo', 'pantalone': 'aprile', 'camicia': 'aprile'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi3.csv'],{'giacca': 'marzo', 'pantalone': 'aprile', 'camicia': 'febbraio'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi4.csv'],{'giacca': 'marzo', 'pantalone': 'aprile', 'camicia': 'febbraio'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi5.csv'],{'giacca': 'aprile', 'pantalone': 'aprile', 'camicia': 'aprile'})

    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
