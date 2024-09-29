#include "Calculator.h"
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), firstNumber(0), secondNumberStarted(false) {
    // Creazione del display
    display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);
    
    // Chiamata alla funzione per creare il layout
    createLayout();
}

void Calculator::createLayout() {
    // Layout principale
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    // Aggiunta del display alla finestra
    mainLayout->addWidget(display);
    
    // Layout per i pulsanti
    QGridLayout *buttonLayout = new QGridLayout();
    
    // Creazione dei pulsanti numerici
    QStringList buttonLabels = {"7", "8", "9", "/",
                                "4", "5", "6", "*",
                                "1", "2", "3", "-",
                                "0", "C", "=", "+"};

    int row = 0;
    int col = 0;
    for (const QString &text : buttonLabels) {
        QPushButton *button = new QPushButton(text);
        button->setFixedSize(40, 40);
        buttonLayout->addWidget(button, row, col);
        col++;
        if (col == 4) {
            col = 0;
            row++;
        }

        // Collegamento dei pulsanti ai relativi slot
        if (text == "C") {
            connect(button, &QPushButton::clicked, this, &Calculator::onClearPressed);
        } else if (text == "=") {
            connect(button, &QPushButton::clicked, this, &Calculator::onEqualPressed);
        } else if (text == "+" || text == "-" || text == "*" || text == "/") {
            connect(button, &QPushButton::clicked, this, &Calculator::onOperatorPressed);
        } else {
            connect(button, &QPushButton::clicked, this, &Calculator::onDigitPressed);
        }
    }
    
    mainLayout->addLayout(buttonLayout);
    setCentralWidget(centralWidget);
}

void Calculator::onDigitPressed() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString buttonValue = button->text();

    if (secondNumberStarted) {
        display->clear();
        secondNumberStarted = false;
    }

    display->setText(display->text() + buttonValue);
}

void Calculator::onOperatorPressed() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    currentOperator = button->text();
    firstNumber = display->text().toDouble();
    secondNumberStarted = true;
}

void Calculator::onClearPressed() {
    display->clear();
    firstNumber = 0;
    secondNumberStarted = false;
}

void Calculator::onEqualPressed() {
    double secondNumber = display->text().toDouble();
    double result = 0;

    if (currentOperator == "+") {
        result = firstNumber + secondNumber;
    } else if (currentOperator == "-") {
        result = firstNumber - secondNumber;
    } else if (currentOperator == "*") {
        result = firstNumber * secondNumber;
    } else if (currentOperator == "/") {
        if (secondNumber != 0) {
            result = firstNumber / secondNumber;
        } else {
            display->setText("Error");
            return;
        }
    }

    display->setText(QString::number(result));
}