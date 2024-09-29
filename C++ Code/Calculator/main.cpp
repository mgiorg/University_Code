#include <QApplication>
#include "Calculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Creazione dell'oggetto Calculator
    Calculator calculator;
    calculator.show();
    
    return app.exec();
}