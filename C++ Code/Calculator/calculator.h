#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

class Calculator : public QMainWindow {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void onDigitPressed();
    void onOperatorPressed();
    void onClearPressed();
    void onEqualPressed();

private:
    QLineEdit *display;
    QString currentOperator;
    double firstNumber;
    bool secondNumberStarted;
    
    void createLayout();
};

#endif // CALCULATOR_H