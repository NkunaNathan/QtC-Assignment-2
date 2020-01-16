#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QThread>

#include"investmentcalculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QStringList compoundResults;
    InvestmentCalculator *investmentCalc;
    QThread *threadCalc;
private slots:
    void updateResults(double results);
    void updateThread();
    void disableWidget();
    void enableWidget();
    void evaluateCalculation();
};

#endif // MAINWINDOW_H
